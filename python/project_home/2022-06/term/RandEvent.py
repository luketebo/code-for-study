import random
# data = {
#     "Map":[
#             [0,2,5,-1,-1,-1,-1,-1,-1,-1],
#             [2,0,-1,2,3,-1,3,-1,-1,-1],
#             [5,-1,0,4,-1,-1,-1,3,-1,-1],
#             [-1,2,4,0,-1,-1,1,-1,2,-1],
#             [2,3,-1,-1,0,10,-1,-1,-1,3],
#             [-1,-1,-1,-1,10,0,1,-1,-1,-1],
#             [-1,3,-1,1,-1,1,0,-1,-1,2],
#             [-1,-1,3,-1,-1,-1,-1,0,-1,-1],
#             [-1,-1,-1,2,-1,-1,-1,-1,-1,-1],
#             [-1,-1,-1,-1,3,-1,2,-1,-1,0]
#         ],
#     "Scheme":{
#         "101":{
#             "Path":[0,1,4,5],
#             "Time":["9:30","9:50","10:00","10:15"]
#         },
#         "102":{
#             "Path":[8,3,6,9,4],
#             "Time":["9:50","10:00","10:15","10:30"]
#         },
#         "103":{
#             "Path":[7,2,3,1],
#             "Time":["9:30","10:00","10:30","11:00"]
#         }
#     }
data = {
        "101":{
            "Path":[0,1,4,5],
            "Time":["9:30","9:50","10:00","10:15"]
        },
        "102":{
            "Path":[8,3,6,9,4],
            "Time":["9:50","10:00","10:15","10:30"]
        }
    }

# 制造随机事件 并返回结果
def rand_event(data):
    # a : key   b : value
    a, b  = random.choice(list(data.items()))
    print(a)
    print(b)
    pass

# 输入上车时间 返回合理的下车时间
def get_down_time(data, up_time):
    beg =  int(up_time.split(":")[0])
    end = int(up_time.split(":")[1])
    for i in data.keys():
        for x in range(len(data[i]["Time"])):
            tmp_beg = int(data[i]["Time"][x].split(":")[0])
            tmp_end = int(data[i]["Time"][x].split(":")[1])
            if (beg < tmp_beg | end < tmp_end):
                pass
            if up_time == data[i]["Time"][x]:
                return data[i]["Time"][x+1]
    # print(data["102"]["Time"][3])
    # print(up_time.split(":")[0])
    # print("10:30" - "9:30")

        
    pass

if __name__ == "__main__":
    # rand_event(data)
    print(get_down_time(data, "9:30"))