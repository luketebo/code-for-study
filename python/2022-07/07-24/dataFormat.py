# 导入读取xlsx的包
import pandas as pd
import os
import warnings
warnings.filterwarnings('ignore')


# 数据处理
def dataDeal():
    excel = pd.read_excel('data.xlsx')
    excel_list = excel.values.tolist()
    result_1 = []
    result_2 = []
    result_3 = []
    for s_li in excel_list:
        result_1.append(s_li[3])
        result_2.append(s_li[10])
        result_3.append(s_li[17])
    del result_1[0]
    del result_2[0]
    del result_3[0]
    list_new = []
    for i in result_1:
        list_new.append(i)
    for i in result_2:
        list_new.append(i)
    for i in result_3:
        list_new.append(i)
    return list_new


# 数据解析
def dataAnylsis():
    result = dataDeal()
    dic = {}
    for x in result:
        i = 0
        for y in result:
            if x == y:
                i = i + 1
        dic.update({x: i})
    dic_sort = sorted(dic.items(), key=lambda x:x[1], reverse=True)
    print(dic_sort)


# 运行测试
if __name__ == '__main__':
    # dataDeal()
    dataAnylsis()
    pass
