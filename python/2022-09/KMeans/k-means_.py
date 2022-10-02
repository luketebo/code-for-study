from random import sample
import numpy as np
import matplotlib.pyplot as plt
import os


def L2(vecXi, vecXj):
    """
    计算欧氏距离
    para vecXi: 点坐标，向量
    para vecXj: 点坐标，向量
    return: 两点之间的欧氏距离
    """
    return np.sqrt(np.sum(np.power(vecXi - vecXj, 2)))


def kMeans(S, k, distMeas=L2):
    """K均值聚类

    Args:
        S (_type_): 样本集，多维数组
        k (_type_): 簇个数
        distMeas (_type_, optional): _description_. Defaults to L2.
    """
    print(np.shape(S))
    m = np.shape(S)[0]  # 样本总数
    sampleTag = np.zeros(m)

    # 随机产生k个初始簇中心
    n = np.shape(S)[1]  # 样本向量特征数
    # print(n)
    clusterCents = np.mat(np.zeros((k, n)))
    for j in range(n):
        minJ = min(S[:, j])
        rangeJ = float(max(S[:, j]) - minJ)
        clusterCents[:, j] = np.mat(minJ + rangeJ * np.random.rand(k, 1))

    sampleTagChanged = True
    SSE = 0.0
    while sampleTagChanged:
        sampleTagChanged = False
        SSE = 0.0

        # 计算每个样本点到各个簇中心的距离
        for i in range(m):
            minD = np.inf
            minIndex = -1
            for j in range(k):
                d = distMeas(clusterCents[j, :], S[i, :])
                if d < minD:
                    minD = d
                    minIndex = j
            if sampleTag[i] != minIndex:
                sampleTagChanged = True
            sampleTag[i] = minIndex
            SSE += minD ** 2
        # print(clusterCents)
        # plt.scatter(S[:,0],S[:,1],c=sampleTag, linewidths = np.power(sampleTag + 0.5, 2))
        # plt.show()
        print(SSE)

        # 重新计算簇中心
        for i in range(k):
            ClustI = S[np.nonzero(sampleTag[:] == i)[0]]
            clusterCents[i, :] = np.mean(ClustI, axis=0)

    return clusterCents, sampleTag, SSE


if __name__ == "__main__":
    print(os.getcwd())
    samples = np.loadtxt("kmeansSamples.txt")
    clusterCents, sampleTag, SSE = kMeans(samples, 3)
    plt.scatter(samples[:, 0], samples[:, 1], c=sampleTag, linewidths=np.power(sampleTag + 0.5, 2))
    plt.show()
    print(clusterCents)
    print(SSE)
