import requests 

url="http://www.baidu.com"
r = requests.get(url)

print(r.status_code)
print(r.encoding)
print(r.apparent_encoding)

# params = {'name':'germey'}
