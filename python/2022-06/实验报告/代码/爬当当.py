from encodings import utf_8
import requests
from bs4 import BeautifulSoup
import re
def getHTMLText(url):
    try:
        r = requests.get(url, timeout=100)
        r.raise_for_status()
        r.encoding = 'GBK'
        #r.encoding = 'UTF-8'
        return r.text
    except:
        return ""

def parsePage(ilt, html):
    try:
        soup = BeautifulSoup(html, 'html.parser')
        '''
        f = open("ceshi.txt", 'w', encoding="UTF-8")
        f.write(str(soup))
        f.close()
        '''
        names = soup.find_all('div', attrs = {'class': 'name'})
        writers = soup.find_all('div', attrs={'class': 'publisher_info'})
        price_ns = soup.find_all('span', 'price_n')
        price_rs = soup.find_all('span', 'price_r')
        for i in range(len(names)):
            publisher = writers[2*i].text.split('（')[0].split(' ')[0].split(',')[0].split('，')[0].replace('?','·')
            title = names[i].text.split('（')[0].split('（')[0].split(' ')[0].split('(')[0].replace('——','--')
            price_n = price_ns[i].string
            price_r = price_rs[i].string
            #print(price_n, price_r)
            ilt.append([publisher, title, price_n, price_r])
    except:
        print("")

def printGoodsList(ilt):
    print(my_format('序号', 8, 'l') + my_format('书名', 25, 'l') +\
          my_format('作者', 15, 'l') + my_format('当前价格', 8, 'l') + my_format('定价', 8, 'l'))
    count = 0

    for g in ilt:
        count = count + 1
        print(my_format(str(count), 8, 'l') + my_format(g[1], 25, 'l') + \
              my_format(g[0], 15, 'l') + my_format(g[2], 8, 'l') + my_format(g[3], 8, 'l'))

def my_format(str, width, align):#定义函数接受三个参数：要输出的字符串(str)、总占用宽度（int）、对齐方式（str:l、r对应左右）
    sigle = 0
    double = 0
    longkong = 0
    sep=' '#定义占位符
    long_sep = '　'
    for i in str:#统计单字宽和1.6字宽的数目
        if len(i.encode('UTF-8')) == 1 or len(i.encode('UTF-8')) == 2:
            sigle += 1
        elif len(i.encode('UTF-8')) == 3:
            double += 1
    if double % 5 != 0:
        longkong = (5 - double % 5)
        double += longkong
    if align == 'l':
        return str + long_sep * longkong + int(width * 2 - sigle - double * 1.6) * sep
    elif align == 'r':
        return long_sep * longkong + int(width * 2 - sigle - double * 1.6) * sep + str

def main():
    kind = '01.03.52.00.00.00'#排行榜书的类别，这个种类是影视小说
    time = '-year-2020-0-1'#2020年整年的排行榜
    depth = 10#页数
    start_url = 'http://bang.dangdang.com/books/bestsellers/' + kind + time + '-'
    infoList = []
    for i in range(depth):
        try:
            url = start_url + str(i+1)
            html = getHTMLText(url)
            parsePage(infoList, html)
        except:
            continue
    printGoodsList(infoList)
    print("-----------------------------------------------")
    for i in infoList:
        print(i)
        with open("test.txt", "a", encoding="utf_8") as f:
            f.write(str(i) + '\n')

main()
