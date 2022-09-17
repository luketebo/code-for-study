# k-means 聚类分析
import pandas as pd
import numpy as np
from sklearn.cluster import KMeans
import os

print(os.getcwd())
dataA = pd.read_excel("wind.xlsx")
print(dataA)
data = dataA['Wind']
print(data)

# 数据处理


data = np.array(data)
print(data)
# 数组转换成为列表并且进行遍历
data = [[i] for i in data]
print(data)

# 1.4k-Means 聚类
juLei = KMeans(n_clusters=4)
juLei.fit(data)

label = juLei.labels_
center = juLei.cluster_centers_
print(label)
print("------------------------------")
# 二维聚类
data1 = dataA['Wind']
data1 = np.array(data1)

data2 = dataA['Temp']
data2 = np.array(data2)

DATA2 = np.vstack((data1, data2)).T

print(DATA2)

juLei = KMeans(n_clusters=4)  # 进行Kmeans聚类
juLei.fit(DATA2)
label = juLei.labels_
print(label)
