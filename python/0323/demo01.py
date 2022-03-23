from re import I


def Factorial():
    n = int(input("n="))
    t = 1
    s = 0
    for i in range(1, n+1):
        t *= i
        s += t
    print(f"s={s}")


def Factorial_02():
    n = int(input("n="))
    t = 1
    s = 0
    for i in range(1, n+1):
        s += t
        for j in range(1, t+1):
            t *= i
    print(f"s={s}")


def FindNum():
    for i in range(60042, 69943):
        if i % 57 == 0 and i % 67 == 0:
            print(f"number={i}")


def Monkey(n):
    peaches = 2
    s = 2
    for i in range(1, n):
        peaches = peaches * 2 + 1
        s += peaches
    print(f"p={peaches}")
    print(f"p={s}")


def EatPeaches():
    t = 1
    for i in range(1, 10):
        t = (t + 1) * 2
    print(f"t = {t}")


def Multiplication():
    for i in range(1, 10):
        for j in range(1, i+1):
            print(f"{j}*{i}={i*j:-2} ", end=" ")
        print(" ")


def chick_and_hundred():
    for x in range(1, 101):
        for y in range(1, 101):
            z = 100 - x - y
            if z % 3 == 0 and x * 5 + y * 3 + z/3 == 100:
                print(f"x={x} y={y} z={z}")


def Traversal_string():
    s = input()
    a, b, c, d, e = 0, 0, 0, 0, 0


def Findthe_7():
    for i in range(1, 101):
        if i == 7 or i % 7 == 0:
            print(f"{i} 拍手 ")


def test():
    try:
        print(5/0)
    except:
        print("fuck you")
    print("焯")
    
def Sensitive():
    n = input()
    # for i in n:
        

# def 