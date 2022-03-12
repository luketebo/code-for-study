import requests
for i in range(100):
    print(f"正在爬去第{i}张图片")
    with open(f"{i:0>2d}.jpg","wb") as f:
        r = requests.get("https://api.ixiaowai.cn/api/api.php")
        f.write(r.content)
        f.close()