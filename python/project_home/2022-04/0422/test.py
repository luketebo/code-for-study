from re import I
from soupsieve import Dict


voctionary = set()


def show():
    print(voctionary)
    
def add(key, value):
    word = (key, value)
    voctionary.add(word)
    
def remove():
    key = input("请输入要删除的单词：")
    value = input("请输入要删除的单词的意思：")
    test = (key, value)
    word = set()
    word.add(test)
    if word in voctionary:
        voctionary.remove(word)
        print("删除成功")
    else:
        print("删除失败")
    
def clear():
    voctionary.clear()
    print("清空成功")
    
def recite():
    dic = {}
    lis_1 = []
    lis_2 = []
    flag = True
    for item in voctionary:
        print(item)
        for i in list(item):
            if flag == True:
                lis_1.append(i)
                flag = False
            else:
                lis_2.append(i)
                flag = True
        
    dic = dict(zip(lis_1, lis_2))
    for key, value in dic.items():
        answer = input(f"{key}的意思是：")
        if answer == value:
            print("回答正确")
        else:
            print("回答错误")
    
    
def main():
    print("欢迎使用生词记录器")
    print("1. 查看生词本")
    print("2. 背单词")
    print("3. 添加生词")
    print("4. 删除单词")
    print("5. 清空单词本")
    print("6. 退出生词记录器")
    print("================")
    while True:
        num = int(input("请输入您的选择："))
        if num == 1:
            show()
        elif num == 2:
            recite()
        elif num == 3:
            key = input("请输入要添加的单词：")
            value = input("请输入要添加的单词的意思：")
            add(key, value)
        elif num == 4:
            remove()
        elif num == 5:
            clear()
        elif num == 6:
            break
        else:
            print("输入错误，请重新输入")
            
main()