import os,sys
import hashlib
import requests
import json
import re
from bs4 import BeautifulSoup
import base64
from Crypto.Cipher import DES
import time


FATEA_PRED_URL  = "http://pred.fateadm.com"

def LOG(log):
    # 不需要测试时，注释掉日志就可以了
    print(log)
    log = None

class TmpObj():
    def __init__(self):
        self.value  = None

class Rsp():
    def __init__(self):
        self.ret_code   = -1
        self.cust_val   = 0.0
        self.err_msg    = "succ"
        self.pred_rsp   = TmpObj()

    def ParseJsonRsp(self, rsp_data):
        if rsp_data is None:
            self.err_msg     = "http request failed, get rsp Nil data"
            return
        jrsp                = json.loads( rsp_data)
        self.ret_code       = int(jrsp["RetCode"])
        self.err_msg        = jrsp["ErrMsg"]
        self.request_id     = jrsp["RequestId"]
        if self.ret_code == 0:
            rslt_data   = jrsp["RspData"]
            if rslt_data is not None and rslt_data != "":
                jrsp_ext    = json.loads( rslt_data)
                if "cust_val" in jrsp_ext:
                    data        = jrsp_ext["cust_val"]
                    self.cust_val   = float(data)
                if "result" in jrsp_ext:
                    data        = jrsp_ext["result"]
                    self.pred_rsp.value     = data

def CalcSign(pd_id, passwd, timestamp):
    md5     = hashlib.md5()
    md5.update((timestamp + passwd).encode())
    csign   = md5.hexdigest()

    md5     = hashlib.md5()
    md5.update((pd_id + timestamp + csign).encode())
    csign   = md5.hexdigest()
    return csign

def CalcCardSign(cardid, cardkey, timestamp, passwd):
    md5     = hashlib.md5()
    md5.update(passwd + timestamp + cardid + cardkey)
    return md5.hexdigest()

def HttpRequest(url, body_data, img_data=""):
    rsp         = Rsp()
    post_data   = body_data
    files       = {
        'img_data':('img_data',img_data)
    }
    header      = {
            'User-Agent': 'Mozilla/5.0',
            }
    rsp_data    = requests.post(url, post_data,files=files ,headers=header)
    rsp.ParseJsonRsp( rsp_data.text)
    return rsp

class FateadmApi():
    # API接口调用类
    # 参数（appID，appKey，pdID，pdKey）
    def __init__(self, app_id, app_key, pd_id, pd_key):
        self.app_id     = app_id
        if app_id is None:
            self.app_id = ""
        self.app_key    = app_key
        self.pd_id      = pd_id
        self.pd_key     = pd_key
        self.host       = FATEA_PRED_URL

    def SetHost(self, url):
        self.host       = url



    #
    # 识别验证码
    # 参数：pred_type:识别类型  img_data:图片的数据
    # 返回值：
    #   rsp.ret_code：正常返回0
    #   rsp.request_id：唯一订单号
    #   rsp.pred_rsp.value：识别结果
    #   rsp.err_msg：异常时返回异常详情
    #
    def Predict(self, pred_type, img_data, head_info = ""):
        tm          = str( int(time.time()))
        sign        = CalcSign( self.pd_id, self.pd_key, tm)
        param       = {
                "user_id": self.pd_id,
                "timestamp": tm,
                "sign": sign,
                "predict_type": pred_type,
                "up_type": "mt"
                }
        if head_info is not None or head_info != "":
            param["head_info"] = head_info
        if self.app_id != "":
            #
            asign       = CalcSign(self.app_id, self.app_key, tm)
            param["appid"]     = self.app_id
            param["asign"]      = asign
        url     = self.host + "/api/capreg"
        files = img_data
        rsp     = HttpRequest(url, param, files)
        if rsp.ret_code == 0:
            LOG("predict succ ret: {} request_id: {} pred: {} err: {}".format( rsp.ret_code, rsp.request_id, rsp.pred_rsp.value, rsp.err_msg))
        else:
            LOG("predict failed ret: {} err: {}".format( rsp.ret_code, rsp.err_msg))
            if rsp.ret_code == 4003:
                #lack of money
                LOG("cust_val <= 0 lack of money, please charge immediately")
        return rsp

    #
    # 从文件进行验证码识别
    # 参数：pred_type;识别类型  file_name:文件名
    # 返回值：
    #   rsp.ret_code：正常返回0
    #   rsp.request_id：唯一订单号
    #   rsp.pred_rsp.value：识别结果
    #   rsp.err_msg：异常时返回异常详情
    #
    def PredictFromFile( self, pred_type, file_name, head_info = ""):
        with open(file_name, "rb") as f:
            data = f.read()
        return self.Predict(pred_type,data,head_info=head_info)



    ##
    # 从文件识别验证码，只返回识别结果
    # 参数：pred_type;识别类型  file_name:文件名
    # 返回值： rsp.pred_rsp.value：识别的结果
    ##
    def PredictFromFileExtend( self, pred_type, file_name, head_info = ""):
        rsp = self.PredictFromFile(pred_type,file_name,head_info)
        return rsp.pred_rsp.value

    ##
    # 识别接口，只返回识别结果
    # 参数：pred_type:识别类型  img_data:图片的数据
    # 返回值： rsp.pred_rsp.value：识别的结果
    ##
    def PredictExtend(self,pred_type, img_data, head_info = ""):
        rsp = self.Predict(pred_type,img_data,head_info)
        return rsp.pred_rsp.value



def TestFunc():
    pd_id           = "128608"     #用户中心页可以查询到pd信息
    pd_key          = "sPthSBZsIJke8Lt/spl5GM8E+d2sJyRw"
    app_id          = "328608"     #开发者分成用的账号，在开发者中心可以查询到
    app_key         = "i8FtBK6SbWOxNJieS0l6beRcmp0GJN24"
    #识别类型，
    #具体类型可以查看官方网站的价格页选择具体的类型，不清楚类型的，可以咨询客服
    pred_type       = "30400"
    api             = FateadmApi(app_id, app_key, pd_id, pd_key)

    # 通过文件形式识别：
    file_name       = "test.png"
    # 多网站类型时，需要增加src_url参数，具体请参考api文档: http://docs.fateadm.com/web/#/1?page_id=6
    # result =  api.PredictFromFileExtend(pred_type,file_name)   # 直接返回识别结果
    rsp = api.PredictFromFileExtend(pred_type, file_name)  # 返回详细识别结果
    return rsp







def encrypt_des(cipher,key):
    if cipher is None:
        return ""
        # ECB方式
    generator = DES.new(key.encode('utf-8'), DES.MODE_ECB)
        # 非8整数倍明文补位
    pad = 8 - len(cipher) % 8
    pad_str = ""
    for i in range(pad):
        pad_str = pad_str + chr(pad)
        # 加密
    encrypted = generator.encrypt((cipher + pad_str).encode("utf-8"))
        # 编码得密文
    result = base64.b64encode(encrypted)
    return result


code_headers = {
        'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8',
        'Accept-Language': 'en',
        'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_14_6) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.163 Safari/537.36',
        'Host':'csxrz.cqnu.edu.cn',
        'Referer':'http://csxrz.cqnu.edu.cn/cas/login?service=http://202.202.209.15:8081/index.html'
    }

login_headers = {
        'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8',
        'Accept-Language': 'en',
        'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_14_6) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.163 Safari/537.36',
        'Host':'csxrz.cqnu.edu.cn',
        'Referer':'http://csxrz.cqnu.edu.cn/cas/login?service=http://202.202.209.15:8081/index.html',
        'Origin':'http://csxrz.cqnu.edu.cn',
        'X-Requested-With':'XMLHttpRequest'
    }
index_headers = {
        'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8',
        'Accept-Language': 'en',
        'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_14_6) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.163 Safari/537.36',
        'Referer':'http://202.202.209.15:8081/'
    }
book_headers = {
        'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8',
        'Accept-Language': 'en',
        'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_14_6) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.163 Safari/537.36',
        'Referer':'http://202.202.209.15:8081/product/show.html?id=142',
        'Origin':'http://202.202.209.15:8081',
        'X-Requested-With':'XMLHttpRequest',
        'Host':'202.202.209.15:8081'
    }

if __name__ == '__main__':
    session = requests.Session()
    r = session.get("http://202.202.209.15:8081/index.html",headers = index_headers)
    soup = BeautifulSoup(r.content,"html.parser")
    current_time = str(int(time.time()*1000))
    url_image = "https://csxrz.cqnu.edu.cn:443/cas/verCode?random==" + current_time
    r = session.get(url_image, headers=code_headers)
    f = open('test.png','wb')
    f.write(r.content)
    f.close()
    code = TestFunc()
    #code = "0000"
    inputs = soup.find_all("input")
    key = inputs[4].get("value")[:8]
    execution = inputs[5].get("value")

    password = str(encrypt_des("yanghongqiang:a1",key),encoding="utf-8")

    data = {"username":"2020051615308","password":password,"authCode":code,"lt":inputs[4].get("value"),"execution":execution,"_eventId":"submit","isQrSubmit":"false","qrValue":"","isMobileLogin":"false"}
    # r = session.post("http://csxrz.cqnu.edu.cn/cas/login?service=http://202.202.209.15:8081/index.html",data = data,headers = login_headers)
    r = session.post("https://csxrz.cqnu.edu.cn/cas/login?service=https://csxmh.cqnu.edu.cn/PersonalApplications/viewPage?active_nav_num=1", data=data,
                     headers=login_headers)

    #新版本登录进去没有提示 直接预定
    json_data = {"stock": {"20417": "1", }, "extend": {}}
    json_data = json.dumps(json_data)
    data = {"param": json_data, "json": True}
    print(data)
    url = "http://202.202.209.15:8081/order/tobook.html"
    s = session.get(url, )
    r = session.post(url, data=data, headers=login_headers)
    print(r.text)
    #旧版本
    # if("座位预约系统" in r.text):
    #     break
    # if("密码错误" in r.text):
    #     print("密码错误")
    #     break
    # if("验证码输入错误" in r.text):
    #     continue
# json_data = {"stock": {"20330": "1", }, "extend": {}}
# json_data = json.dumps(json_data)
# data = {"param":json_data,"json":True}
# print(data)
# url = "http://202.202.209.15:8081/order/tobook.html"
# r = session.post(url,data = data,headers = login_headers)
# print(r.text) 