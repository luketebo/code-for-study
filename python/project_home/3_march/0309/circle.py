import math


def circle():
    a =  float(input("请输入半径: "))
    Pi = 3.14
    print ("周长 : %f 面积 : %f 体积: %f" %(a * 2 * Pi, a * a * Pi, 4 / 3 * Pi * a ** 3 ))
    
def change():
    a = int(input("请输入三位正整数: "))
    x = a/100
    y = (a%100)/10
    z = a%10
    print("立方和: %f" % (x ** 3 + y ** 3 + z ** 3))
    
def sin():
    a = float(input("请输入斜边: "))
    b = float(input("请输入直角边: "))
    c = math.sqrt(a ** 2 + b ** 2)
    sin = b / a
    cos = c / a
    tan = a / c
    print("sin: %f cos: %f tan: %f" % (sin,cos,tan))
    

##本实例要求编写程序，实现接收用户输入的三角形边长，计算三角形面积的功能

    
def triangle_area():
    a = float(input("请输入底边: "))
    b = float(input("请输入斜边: "))
    c = math.sqrt(a ** 2 - b / 2)
    print("三角形面积: %f" % a * c * 0.5)
    
    
## 已知三角形三边长度分别为x、y、z，其半周长为q，根据海伦公式计算三角形面积S
## 三角形半周长q=(x+y+z)/2
## 三角形面积S = (q*(q-x)*(q-y)*(q-z))开平方


def Triangle_Herion():
    x = float(input("请输入底边: "))
    y = float(input("请输入左斜边: "))
    z = float(input("请输入右斜边: "))
    q = (x + y + z) / 2
    s = (q * (q - x) * (q - y) * (q - z) )
    print("半周长: %f 面积: %f" % (q,s))
    
