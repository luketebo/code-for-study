import math

def readExcel():
    
    pass

def addCore():
    Core = []
    ls = int(input("输入课程数量："))
    if ls.isdigit():
       pass
    else:
        pass
    for i in range(1, ls+1):
        c = float(input("第"+ str(i) +"节课程成绩: "))
        g = float(input("第" + str(i) + "节课程学分: "))
        demo = [c, g]
        Core.append(demo)
    up = 0
    xueFen = 0
    for i in range(ls):
        # up = float(Core[1][0]) + up
        xueFen = float(Core[i][1]) + xueFen
        up = float(Core[i][0]) * float(Core[i][1]) + up
     
    print(up)
    print(xueFen)
    print(up / xueFen)


if __name__ == "__main__":
    addCore()
    pass



