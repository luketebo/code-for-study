import random
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
import dataFormat as df


# 计算欧拉距离
def calcDis(dataSet, centroids, k):
    clalist = []
    for data in dataSet:
        diff = np.tile(data, (k,
                              1)) - centroids  # 相减   (np.tile(a,(2,1))就是把a先沿x轴复制1倍，即没有复制，仍然是 [0,1,2]。 再把结果沿y方向复制2倍得到array([[0,1,2],[0,1,2]]))
        squaredDiff = diff ** 2  # 平方
        squaredDist = np.sum(squaredDiff, axis=1)  # 和  (axis=1表示行)
        distance = squaredDist ** 0.5  # 开根号
        clalist.append(distance)
    clalist = np.array(clalist)  # 返回一个每个点到质点的距离len(dateSet)*k的数组
    return clalist


# 计算质心
def classify(dataSet, centroids, k):
    # 计算样本到质心的距离
    clalist = calcDis(dataSet, centroids, k)
    # 分组并计算新的质心
    minDistIndices = np.argmin(clalist, axis=1)  # axis=1 表示求出每行的最小值的下标
    newCentroids = pd.DataFrame(dataSet).groupby(
        minDistIndices).mean()  # DataFramte(dataSet)对DataSet分组，groupby(min)按照min进行统计分类，mean()对分类结果求均值
    newCentroids = newCentroids.values

    # 计算变化量
    changed = newCentroids - centroids

    return changed, newCentroids


# 使用k-means分类
def kmeans(dataSet, k):
    # 随机取质心
    centroids = random.sample(dataSet, k)

    # 更新质心 直到变化量全为0
    changed, newCentroids = classify(dataSet, centroids, k)
    while np.any(changed != 0):
        changed, newCentroids = classify(dataSet, newCentroids, k)

    centroids = sorted(newCentroids.tolist())  # tolist()将矩阵转换成列表 sorted()排序

    # 根据质心计算每个集群
    cluster = []
    clalist = calcDis(dataSet, centroids, k)  # 调用欧拉距离
    minDistIndices = np.argmin(clalist, axis=1)
    for i in range(k):
        cluster.append([])
    for i, j in enumerate(minDistIndices):  # enymerate()可同时遍历索引和遍历元素
        cluster[j].append(dataSet[i])

    return centroids, cluster


# 创建数据集
def createDataSet():
    """
    [[36.28', '47.43'], ['20.14', '28.68'], ['4.61', '32.45'], ['33.59', '25.39'], ['29.64', '42.82'], ['37.36', '9.3'], ['53.79', '16.98'], ['31.94', '29.14'], ['50.61', '31.9'], ['19.79', '29.53'], ['3.72', '29.92'], ['68.08', '17.14'], ['63.3', '12.31'], ['34.34', '39.22'], ['36.93', '37.74'], ['65.91', '16.55'], ['69.71', '19.76'], ['75.51', '16.16'], ['35.78', '46.55'], ['65.91', '22.05'], ['39.57', '41.61'], ['60.12', '17.24'], ['32.93', '49.31'], ['26.25', '61.03'], ['16.71', '70.21'], ['18.46', '44.12'], ['51.26', '21.88'], ['51.33', '20.12'], ['12.41', '59.85'], ['21.7', '44.75'], ['60.74', '13.61'], ['61.28', '15.99'], ['55.21', '25.25'], ['51.54', '25.4'], ['53.33', '15.71'], ['28.79', '34.18'], ['54.61', '23.02'], ['17.98', '44'], ['45.02', '30.61'], ['24.61', '40.24'], ['21.35', '51.34'], ['25.74', '47.42'], ['63.66', '13.66'], ['22.28', '55.46'], ['17.11', '58.46'], ['49.01', '32.92'], ['29.15', '41.25'], ['25.42', '45.1'], ['30.39', '39.35']]

    :return:
    """
    return [[36.28, 47.43], [20.14, 28.68], [4.61, 32.45], [33.59, 25.39], [29.64, 42.82], [37.36, 9.3], [53.79, 16.98], [31.94, 29.14], [50.61, 31.9], [19.79, 29.53], [3.72, 29.92],[68.08, 17.14], [63.3, 12.31], [34.34, 39.22], [36.93, 37.74], [65.91, 16.55],[69.71, 19.76], [75.51, 16.16], [35.78, 46.55], [65.91, 22.05], [39.57, 41.61],[60.12, 17.24], [32.93, 49.31], [26.25, 61.03], [16.71, 70.21], [18.46, 44.12],[51.26, 21.88], [51.33, 20.12], [12.41, 59.85], [21.7, 44.75], [60.74, 13.61],[61.28, 15.99], [55.21, 25.25], [51.54, 25.4], [53.33, 15.71], [28.79, 34.18],[54.61, 23.02], [17.98, 44], [45.02, 30.61], [24.61, 40.24], [21.35, 51.34],[25.74, 47.42], [63.66, 13.66], [22.28, 55.46], [17.11, 58.46], [49.01, 32.92],[29.15, 41.25], [25.42, 45.1], [30.39, 39.35]]

# [[36.28, 47.43], [20.14, 28.68], [4.61, 32.45], [33.59, 25.39], [29.64, 42.82],
#      [37.36, 9.3], [53.79, 16.98], [31.94, 29.14], [50.61, 31.9], [19.79, 29.53], [3.72, 29.92],
#      [68.08, 17.14], [63.3, 12.31], [34.34, 39.22], [36.93, 37.74], [65.91, 16.55],
#      [69.71, 19.76], [75.51, 16.16], [35.78, 46.55], [65.91, 22.05], [39.57, 41.61],
#      [60.12, 17.24], [32.93, 49.31], [26.25, 61.03], [16.71, 70.21], [18.46, 44.12],
#      [51.26, 21.88], [51.33, 20.12], [12.41, 59.85], [21.7, 44.75], [60.74, 13.61],
#      [61.28, 15.99], [55.21, 25.25], [51.54, 25.4], [53.33, 15.71], [28.79, 34.18],
#      [54.61, 23.02], [17.98, 44], [45.02, 30.61], [24.61, 40.24], [21.35, 51.34],
#      [25.74, 47.42], [63.66, 13.66], [22.28, 55.46], [17.11, 58.46], [49.01, 32.92],
#      [29.15, 41.25], [25.42, 45.1], [30.39, 39.35]]
    # return [[1, 1], [1, 2], [2, 1], [6, 4], [6, 3], [5, 4]]


if __name__ == '__main__':
    dataset = createDataSet()
    # dataset = df.Format()
    # 质心      集群
    centroids, cluster = kmeans(dataset, 2)
    print('质心为：%s' % centroids)
    print('集群为：%s' % cluster)
    # for i in range(len(dataset)):
    #     # 绘图函数
    #     plt.scatter(dataset[i][0], dataset[i][1], marker='o', color='green', s=40, label='原始点')
    #     #  记号形状       颜色      点的大小      设置标签
    #     for j in range(len(centroids)):
    #         plt.scatter(centroids[j][0], centroids[j][1], marker='x', color='red', s=50, label='质心')
    #         # 显示图形

    # SSE
    SSE = []
    for i in range(1, 11):
        km = KMeans(n_clusters=i)
        km.fit(dataset)
        SSE.append(km.inertia_)
    a = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    plt.plot(a,SSE, color='red')

    plt.show()
