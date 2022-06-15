import requests
from bs4 import BeautifulSoup
import bs4

url = "http://python123.io/ws/demo.html"
r = requests.get(url)
# print(r.status_code)
print(r.text)

print("-------------------------")
# 上行遍历   .contents 子节点 .children 子节点 用来遍历 .descendants 子孙节点 用来遍历
soup = BeautifulSoup(r.text, "html.parser")
for i in soup.body.descendants:
    print(i)
# 平行遍历  .parent 节点的父标签 .parents 节点的父标签 用来循环遍历
for i in soup.p.parents:
    print(i)
    print("fuck")
print("------------分割线-------------")
# 下行遍历  
# .next_sibling  下一个平行标签 .next_siblings 下一个平行标签 用来遍历
# .previous_sibling 上一个平行标签 .previous_siblings 上一个平行标签 用来遍历 
for i in soup.a.next_siblings:
    print(i)
