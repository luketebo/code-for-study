import turtle as T

def test_01():
    
    T.goto(0,0)
    T.color('black')
    T.forward(100)
    T.right(158)  # 五角星度数
    T.forward(100)
    T.right(158)
    T.forward(100)
    T.right(158)
    T.forward(100)
    T.right(158)
    T.forward(100)
    T.right(158)
    T.forward(100)
    T.right(158)
    T.forward(100)
    T.right(158)
    T.forward(100)
    T.right(158)
    T.forward(100)
    T.done()
    
def test_02():
    import json

    with open("identify.text","r",encoding="UTF-8") as f:
        content = f.read()
    content_dict =  json.loads(content) # 转换成字典类型
    print(content_dict)
    # test = input("请输入地名编号")
    
test_02()