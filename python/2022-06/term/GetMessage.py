from os import stat
import random
import math
from re import S
from turtle import position


# 站点映射，坐标和实际地名 一一对应
Station = {
    "0": "菜市场",
    "1":  "中心小学",
    "2": "加油站",
    "3": "医院",
    "4": "幸福小区",
    "5": "长途车站",
    "6": "汽车站",
    "7": "桃花镇",
    "8": "荷花镇",
    "9": "政府",
    "菜市场": "0",
    "中心小学": "1",
    "加油站": "2",
    "医院": "3",
    "幸福小区": "4",
    "长途车站": "5",
    "汽车站": "6",
    "桃花镇": "7",
    "荷花镇": "8",
    "政府": "9"
}
# 各种数据杂糅
Data = {
    "Station": {
        "0": "3,5",
        "1": "3,4",
        "2": "2,4",
        "3": "3,3",
        "4": "5,4",
        "5": "5,1",
        "6": "4,2",
        "7": "1,4",
        "8": "2,1",
        "9": "5,3"
    },
    "Scheme": {
        "101": {
            # A B D I
            "Path": [0, 1, 3, 8],
            "Time":
            {
                "1": ["9:30", "9:50", "10:30", "11:15"],
                "2": ["12:00", "12:20", "13:00", "13:15"],
                "3": ["14:00", "14:20", "15:00", "15:15"]
            }
        },
        "102": {
            # H C D G F
            "Path": [7, 2, 3, 6, 5],
            "Time": {
                "1": ["9:50", "10:00", "10:15", "10:30", "11:00"],
                "2": ["12:00", "12:10", "12:25", "12:40", "13:10"],
                "3": ["14:00", "14:10", "14:25", "14:40", "15:10"]

            }
        },
        "103": {
            # A E J G
            "Path": [0, 4, 9, 6],
            "Time": {
                "1": ["9:30", "10:00", "10:30", "11:00"],
                "2": ["12:00", "12:30", "13:00", "13:30"],
                "3": ["14:00", "14:30", "15:00", "15:30"]
            }
        }
    }
}
# 站点发车信息
Time = {
    "0": ["9:30", "12:00", "14:00"],
    "1": ["9:50", "12:20", "14:20"],
    "2": ["10:00", "12:10", "14:10"],
    "3": ["10:15", "10:30", "12:25", "13:00", "14:25", "15:00"],
    "4": ["10:00", "12:30", "14:30"],
    "5": ["11:00", "13:10", "15:10"],
    "6": ["10:30", "11:00", "12:40", "13:00", "14:40", "15:30"],
    "7": ["9:50", "12:00", "14:00"],
    "8": ["11:15", "13:15", "15:15"],
    "9": ["10:30", "13:00", "15:00"]
}
# 公交路线信息
Bus = {
    "101": ["菜市场", "中心小学", "医院", "荷花镇"],
    "102": ["桃花镇", "加油站", "医院", "汽车站", "长途车站"],
    "103": ["菜市场", "幸福小区", "政府", "汽车站"]
}


def NearestStation(x, y):
    """返回最近站点信息

    Args:
        Data (dict): 全局数据
        x (str): x坐标
        y (str): y坐标
    """
    min = 100
    A = 0
    B = 0
    position = 0
    for i in Data["Station"]:
        a = int(Data["Station"][i].split(",")[0])
        b = int(Data["Station"][i].split(",")[1])
        tmp = math.sqrt((a - x) ** 2 + (b - y) ** 2)
        if min > tmp :
            min = tmp # 记录最小值
            A = a # 记录最小值的坐标
            B = b # 记录最小值的坐标
            position = i
    print(f"最近的站点：\n{Station[position]}")
    # 发车信息
    print(f"发车信息：\n{Time[position]}")
    # 经过路线
    print("经过路线：")
    temp_p = Station[position]
    for item in Bus:
        for i in Bus[item]:
            if temp_p == i:
                for i in Bus[item]:
                    print(i, end=" ")
    


def GetDownTime(up_time, station):
    """输入当前时间 返回合理的上车时间

    Args:
        Time (dict): 全局数据
        up_time (str): 上车时间
        station (str): 上车的站点
    """
    station = Station[station] # 转换
    beg = int(up_time.split(":")[0])
    end = int(up_time.split(":")[1])
    print(f"该站点发车时间：\n{Time[station]}")
    min = 10000000
    tempA = 0
    tempB = 0
    for item in Time[station]:
        tmp_beg = int(item.split(":")[0])
        tmp_end = int(item.split(":")[1])
        if tmp_beg < beg or (tmp_end > end and beg > tmp_end):
            continue 
        if min > ((tmp_beg - beg) * 60 + (tmp_end - end)):
            min = ((tmp_beg - beg) * 60 + (tmp_end - end))
            tempA = tmp_beg
            tempB = tmp_end
    if tempB == 0:
        tempB = str(tempB) + "0"
    print(f"最近一班车时间: \n{tempA}:{tempB}") # 合理的上车时间


def GetStationMessage(station):
    """得到站点信息

    Args:
        Time (dict): 全局数据
        Station (dict): 全局数据
        station (str): 上车的站点
    """
    # 打印发车时间
    station = Station[station]
    print(station)
    print("发车时间：")
    for item in Time[station]:
        print(item, end=" ")

    print("\n")
    station = Station[station]
    # station = int(station)
    for item in Bus:
        for i in Bus[item]:
            if station == i:
                for it in Bus[item]:
                    print(it, end="→")
    pass


if __name__ == "__main__":
    # NearestStation(1, 1)
    GetDownTime("11:00", "桃花镇")
    # GetStationMessage("桃花镇")
    pass
