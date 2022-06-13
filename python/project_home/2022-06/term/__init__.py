import random

data = {
    "Map":[
            [0,2,5,-1,-1,-1,-1,-1,-1,-1],
            [2,0,-1,2,3,-1,3,-1,-1,-1],
            [5,-1,0,4,-1,-1,-1,3,-1,-1],
            [-1,2,4,0,-1,-1,1,-1,2,-1],
            [2,3,-1,-1,0,10,-1,-1,-1,3],
            [-1,-1,-1,-1,10,0,1,-1,-1,-1],
            [-1,3,-1,1,-1,1,0,-1,-1,2],
            [-1,-1,3,-1,-1,-1,-1,0,-1,-1],
            [-1,-1,-1,2,-1,-1,-1,-1,-1,-1],
            [-1,-1,-1,-1,3,-1,2,-1,-1,0]
        ],
    "Scheme":{
        "101":{
            "Path":[0,1,4,5],
            "Time":["9:30","9:50","10:00","10:15"]
        },
        "102":{
            "Path":[8,3,6,9,4],
            "Time":["9:50","10:00","10:15","10:30"]
        },
        "103":{
            "Path":[7,2,3,1],
            "Time":["9:30","10:00","10:30","11:00"]
        }
    }
}

print(list(data["Scheme"]))
listOne = list(data["Scheme"])
print(data["Scheme"][list(data["Scheme"])[0]])
print(random.choices(listOne))
class ran_event:
    def __init__(self) -> None:
        # self.ran_event = random.randint(1, 10)
        self.ran_event_name = ""
    # 制造随机事件
    def get_ran_event(self, data):
        listOne = list(data["Scheme"])
        self.ran_event_name = random.choice(listOne)
        text = f"公交: {self.ran_event_name} 发生了故障， 无法正常运作"
        return text
       
    # 输入上车时间 返回合理的下车时间
    def get_down_time(self, data, up_time):
        
        pass 
    
    
# class print_time:
#     def __init__(self) -> None:
#         pass
    
#     # 输入上车时间 返回 下车时间
#     def get_down_time(self, up_time):
#         pass