import random
from re import I

Data = {
    "Station":{
        "A": "3,5",
        "B": "3,4",
        "C": "2,4",
        "D": "3,3",
        "E": "5,4",
        "F": "5,1",
        "G": "4,2",
        "H": "1,4",
        "I": "2,1",
        "J": "5,3"
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

Time = {
    "0" : ["9:30", "12:00", "14:00"],
    "1" : ["9:50", "12:20", "14:20"],
    "2" : ["10:00", "12:10", "14:10"],
    "3" : ["10:15", "10:30", "12:25", "13:00", "14:25", "15:00"],
    "4" : ["10:00", "12:30", "14:30"],
    "5" : ["11:00", "13:10", "15:10"],
    "6" : ["10:30", "11:00", "12:40", "13:00", "14:40", "15:30"],
    "7" : ["9:50", "12:00", "14:00"],
    "8" : ["11:15", "13:15", "15:15"],
    "9" : ["10:30", "13:00", "15:00"]
}
# c^2 = (x1 - x2) ^ 2 + (y1 - y2) ^ 2  两点之间的距离
import math

def NearestStation(Data, x, y):
    """返回最近的站点

    Args:
        Data (dict)): 全局数据
        x (str): x坐标
        y (str): y坐标
    """
    # a : key   b : value
    # a, b = random.choice(list(data.items()))
    print(Data["Station"])
    min = 100
    A = 0
    B = 0
    for i in Data["Station"]:
        a = int(Data["Station"][i].split(",")[0])
        b = int(Data["Station"][i].split(",")[1])
        tmp = math.sqrt((a - x) ** 2 + (b - y) ** 2)
        if min > tmp :
            min = tmp # 记录最小值
            A = a # 记录最小值的坐标
            B = b # 记录最小值的坐标
    print(A, B) # 最近站点坐标


def GetDownTime(Time, up_time, station):
    """输入当前时间 返回合理的上车时间

    Args:
        Time (dict): 全局数据
        up_time (str): 上车时间
        station (str): 上车的站点
    """
    beg = int(up_time.split(":")[0])
    end = int(up_time.split(":")[1])
    print(Time[station])
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
    print(tempA, tempB) # 合理的上车时间


Station = {
    "101" : [0, 1, 3, 8],
    "102" : [7, 2, 3, 6, 5],
    "103" : [0, 4, 9, 6]
}


def GetStationMessage(Time, Station, station):
    """得到站点信息
    
    Args:
        Time (dict): 全局数据
        Station (dict): 全局数据
        station (str): 上车的站点
    """
    # 打印发车时间
    print(Time[station])
    station = int(station)
    for item in Station:
        for i in Station[item]:
            if station == i:
                print(Station[item])


if __name__ == "__main__":
    # NearestStation(data, 5, 5)
    # GetDownTime(Time, "10:30", "6")
    GetStationMessage(Time, Station,"0")