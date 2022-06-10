import requests
from bs4 import BeautifulSoup

def getHTMLText(url, timeout=30):
    try:
        # r = requests.get(url, timeout=timeout, headers="Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/102.0.5005.63 Safari/537.36 Edg/102.0.1245.33")
        r = requests.get(url)
        r.raise_for_status()
        r.encoding = r.apparent_encoding        
        return r.text
    except:
        return ""

def main():
    url = "https://www.shanghairanking.cn/rankings/bcur/202211"
    html = getHTMLText(url)
    print(html)
    
main()