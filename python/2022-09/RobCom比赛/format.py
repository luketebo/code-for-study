from ast import main
import sys
import os

def resolveFile(file):
    """
    全部转化为txt文件
    """
    path = file.split("/")
    newname = path[-1] + ".txt"
    os.rename(file, newname)

def dataFormat():
    """
    进行数据处理，然后对最大最小进行分析
    """
    with open("Fddd.txt", "r") as f:
        text = f.readlines()
        ls = []
        for item in text:
            item = item.replace("\n", "")
            ls.append(item)
        ls_ = []
        for item in ls:
            item = item.replace("]", "")
            item = item.replace("[", "")
            item = item.split(" ")
            for i in range(len(item))[::-1]:
                if item[i] == "":
                    item.pop(i)
            ls_.append(item)

            min_f, min_s, min_t = sys.maxsize, sys.maxsize, sys.maxsize
            max_f, max_s, max_t = -sys.maxsize, -sys.maxsize, -sys.maxsize

            for item in ls_:
                item[0] = int(item[0])
                item[1] = int(item[1])
                item[2] = int(item[2])
                if item[0] > max_f:
                    max_f = item[0]
                if item[1] > max_s:
                    max_s = item[1]
                if item[2] > max_t:
                    max_t = item[2]
                if item[0] < min_f:
                    min_f = item[0]
                if item[1] < min_s:
                    min_s = item[1]
                if item[2] < min_t:
                    min_t = item[2]
            
            max_f = max_f + 10
            max_s = max_s + 10
            max_t = max_t + 10
            min_f = min_f - 10
            min_s = min_s - 10
            min_t = min_t - 10
            ls_max = [max_f, max_s, max_t]
            ls_min = [min_f, min_s, min_t]
            print(ls_max)
            print(ls_min)

            with open("./TXT/demo.txt", "a") as f:
                f.write(str(ls_max) + "\n")
                f.write(str(ls_min) + "\n")

            # return ls_max, ls_min


if __name__ == '__main__':
    dataFormat()
    pass      
