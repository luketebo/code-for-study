import requests
from bs4 import BeautifulSoup

def getHTMLText(url, timeout=30):
    try:
        # r = requests.get(url, timeout=timeout, headers="Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/102.0.5005.63 Safari/537.36 Edg/102.0.1245.33")
        r = requests.get(url)
        print(r.status_code)
        r.raise_for_status()   # 抛出异常
        r.encoding = r.apparent_encoding        
        return r.text
    except:
        return ""

import bs4
def fillUnivList(uList, html):
   soup = BeautifulSoup(html, "html.parser")
   for tr in soup.find('tbody').children:
       if isinstance(tr, bs4.element.Tag):
           tds = tr('td')
           uniname = tr.a.string
           str1 = str(tds[0].string)
           str3 = str(tds[4].string)
           uList.append([str1.strip(), uniname, str3.strip()])

def printUnivList(uList, num):
    tplt = "{0:^10}\t{1:{3}^10}\t{2:^10}"
    print(tplt.format("排名", "学校名称", "总分", chr(12288)))
    for i in range(num):
        u = uList[i]
        print(tplt.format(u[0], u[1], u[2], chr(12288)))
        with open("univ.txt", "a", encoding="utf-8") as f:
            txt = tplt.format(u[0], u[1], u[2], chr(12288))
            f.write(f"{txt}\n")
    
    

def main():
    uInfo = []
    url = "https://www.shanghairanking.cn/rankings/bcur/202211"
    html = getHTMLText(url)
    fillUnivList(uInfo, html)
    printUnivList(uInfo, 20)
    
    
main()