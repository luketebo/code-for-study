import requests 
url = ''

r = requests.get(url)

path = "D:\python\project_home\6_jun\0601\fuck_01.html" + url.split('/')[-1]
with open(path, 'wb') as f:
    f.write(r.content)