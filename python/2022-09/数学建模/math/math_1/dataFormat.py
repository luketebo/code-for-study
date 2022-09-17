import csv
import numpy as np


def Format():
    data = open("qianBei.CSV", 'rt', encoding='utf-8')
    reader = csv.reader(data)

    headers = next(reader)
    print(headers)

    # 第一个数据 第二个数据
    first_list = []
    second_list = []
    result_list = []

    # 填充数据
    for row in reader:
        first_list.append(row[0])
        second_list.append(row[1])
        result_list.append(first_list + second_list)
        first_list = []
        second_list = []

    # print(result_list)
    result = np.array(result_list)
    print(type(result))
    print(result)
    return result


Format()
