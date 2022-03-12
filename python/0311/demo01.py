from turtle import *

## 字符串拼接

def demo01():
    str1 = input("请输入一个人的名字: ")
    str2 = input("请输入一个国家的名字: ")
    print("世界那么大，{}想去{}看看。".format(str1,str2))


## 整数序列求和


def demo02():
    n = input("请输入整数N: ")
    sum = 0
    for i in range(int(n)):
        sum += i + 1
    print("1 到 N 求和结果: ", sum)
    
    
## 九九乘法表


def demo03():
    for i in range(1,10):
        for j in range(i,i+1):
            print("{}+{}={:2}".format(j,i,j+i),end='')
    print('')
        

## 计算1 + 2！ + 3！ ...... 10!的结果
  
  
def demo04():
    sum, tmp = 0, 1
    for i in range(1,11):
        tmp += i
        sum += tmp
    print("运算结果: {}".format(sum))


## 猴子吃桃


def monkey():
    n = 1;
    for i in range(4,0,-1):
        n = (n + 1)<<1
    print(n)
    
    
## 健康食谱输出

def demo06():
    diet = {'西红柿','花耶菜','黄瓜','牛排','虾仁'}
    for x in range(0,5):
        for y in range(0,5):
            if not(x == y):
                print("{}{}".format(diet[x],diet[y]))      
                
                
## 五角星


def demo07():
    fillcolor("red")
    begin_fill()
    while True:
        forward(200)
        right(144)
        if abs(pos()) < 1:
            break
    end_fill()
    done()



## 太阳花

def demo08():
    color('red','yellow')
    begin_fill()
    while True:
        forward(200)
        left(170)
        if abs(pos()) < 1:
            break
    end_fill()
    done()

demo08()

