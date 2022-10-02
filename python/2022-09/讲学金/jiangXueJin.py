import math
import os
import xlrd
import pandas as pd
import requests
from bs4 import BeautifulSoup


cookies = {
    'JSESSIONID': '7218392789DA796F2501837263A28053-n1',
}

index_headers = {
    'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9',
    'Accept-Language': 'zh-CN,zh;q=0.9',
    'Cache-Control': 'max-age=0',
    'Connection': 'keep-alive',
    # 'Cookie': 'JSESSIONID=7218392789DA796F2501837263A28053-n1',
    'Referer': 'https://csxrz.cqnu.edu.cn/cas/login?service=https%3A%2F%2Fcsxmh.cqnu.edu.cn%2FPersonalApplications%2FviewPage%3Factive_nav_num%3D1',
    'Sec-Fetch-Dest': 'document',
    'Sec-Fetch-Mode': 'navigate',
    'Sec-Fetch-Site': 'same-origin',
    'Sec-Fetch-User': '?1',
    'Upgrade-Insecure-Requests': '1',
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/105.0.0.0 Safari/537.36',
    'sec-ch-ua': '"Google Chrome";v="105", "Not)A;Brand";v="8", "Chromium";v="105"',
    'sec-ch-ua-mobile': '?0',
    'sec-ch-ua-platform': '"Windows"',
}

params = {
    'service': 'https://csxmh.cqnu.edu.cn/PersonalApplications/viewPage?active_nav_num=1',
}

def spider():
    """爬虫部分
    """
    res = requests.get("http://202.202.209.15:8081/index.html", headers=index_headers)
    soup = BeautifulSoup(res.content, "html.parser")
    print(soup)
    pass

def readExcel(path):
    """读取文件数据
    xueFen_row: 学分所在列
    chenJi_row: 成绩所在列
    Args:
        path (_type_): file

    Returns:
        xueFen (list): the all xueFen
        chenJi (list): the all grades
    """
    data = xlrd.open_workbook(path)
    table = data.sheets()[0]
    df = pd.read_excel(path)
    # 学分 xueFen 成绩 chenJi
    xueFen = []
    chenJi = []
    xueFen_row = ""
    chenJi_row = ""
    for i in range(df.shape[0]):
        xueFen.append(df.loc[i].values[int(xueFen_row)])
        chenJi.append(df.loc[i].values[int(chenJi_row)])
        
    return xueFen, chenJi

def resolveCore(xueFen, chenJi):
    Core_0 = 0
    Core_1 = 0
    for i in range(len(xueFen)):
        Core_0 += xueFen[i] * chenJi[i]
        Core_1 += xueFen[i]
    print(Core_0 / Core_1)
        

def addCore():
    Core = []
    ls = int(input("输入课程数量："))
    if ls.isdigit():
       pass
    else:
        pass
    for i in range(1, ls+1):
        c = float(input("第"+ str(i) +"节课程成绩: "))
        g = float(input("第" + str(i) + "节课程学分: "))
        demo = [c, g]
        Core.append(demo)
    up = 0
    xueFen = 0
    for i in range(ls):
        # up = float(Core[1][0]) + up
        xueFen = float(Core[i][1]) + xueFen
        up = float(Core[i][0]) * float(Core[i][1]) + up


if __name__ == "__main__":
    # addCore()
    # print(os.getcwd())
    xueFen, chenJi = readExcel("./2022-09/讲学金/gradeCore.xlsx")
    # resolveCore(xueFen, chenJi)
    # spider()
    pass



