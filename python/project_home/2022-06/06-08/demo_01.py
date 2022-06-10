import requests
from bs4 import BeautifulSoup

def getHTMLText(url):
    try:
        r = requests.get(url, timeout=30)
        r.raise_for_status()
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
    pass

def printUnivList(uList, num):
    print("Suc" + str(num))

def main():
    uInfo = []
    url = "https://www.shanghairanking.cn/rankings/bcur/2022" 
    html = getHTMLText(url)
    fillUnivList(uInfo, html)
    print(uInfo, 20)
    
main()