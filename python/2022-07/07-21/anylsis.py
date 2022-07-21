"""主要是对这次的数据进行分析, 看一下参赛队伍的主要构成
"""
import pandas as pd
import os
# excel = pd.read_excel("data.xlsx")

print(f"当前路径 - {os.getcwd()}")
def read_file():
    with open("D:\Code-repository\Visual Studio Code\python\2022-07\07-21\demo.txt", encoding='utf-8') as f:
        content = f.read();
        print(f"文件内容: {content}")

if __name__ == '__main__':
    read_file()

# print(excel)