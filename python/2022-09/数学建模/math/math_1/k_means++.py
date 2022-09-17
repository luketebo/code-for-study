import csv
import math
import random
from functools import reduce
import matplotlib.pyplot as plt
import numpy


# KMeans++
class KMeeansPP():
    def __init__(self, pBasePoints, pN=5, pPointsCSVName="kmeans_points.csv", pSetCSVName="kmeans_sets.csv"):
        """
        初始化KMeans++算法的构造函数
        :param pBasePoints: 所要计算的数据，为点的二维数组
        :param pN: 所要分成的簇的个数
        :param pPointsCSVName: 所要写入的点集csv文件
        :param pSetCSVName: 所要写入的簇的csv文件
        """
        self.__N = pN
        self.__PCSVName = pPointsCSVName
        self.__SCSVName = pSetCSVName
        self.__M = len(pBasePoints)
        self.__basePoints = pBasePoints

        self.__initBaseCenterPoint()
        self.__initSetsAndNewCenter()
        pass

    def __initBaseCenterPoin(self):
        self.__centerPoints = []
        self.__centerPoints.append(self.__basePoints[random.randint(0, self.__M - 1)])
        while len(self.__centerPoints) < self.__N:
            pass
