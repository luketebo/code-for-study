import imp
from tkinter import PROJECTING


list = []
dic_demo = {}
print("input the price: \n")
for i in range(5):
    value = int(input())
    dic_demo.update({i:value})
    # dic_demo.apppend
    # dic_demo.keys
    # dic_demo.values = int(input())
    
print(sorted(dic_demo.items(),key=lambda s:s[1]))    

list1 = [ [11,12,13],\
          [21,22,23],\
          [31,32,33],\
          [41,42,43] 
          ]
for i in range(4):
    for j in range(3):
        print(list1[i][j],end=' ')
    print()
import random    
stu = []
for i in range(3):
    stu.append([])
    for i in range(5):
        rnd = random.randint(0,101)
        stu[i].append(rnd)
        print(stu[i][j],end=' ')
    print()

stuAve = []
for i in range(3):
    sum = 0
    for j in range(5):
        sum += stu[i][j]
    ave = sum / 5
    stuAve.append(ave)
    print(f'average : {stuAve[i]}',end=' ')
    
stuAvePro = []
for i in range(5):
    Project = 0
    for i in range(3):
        Project += stu[i][j]    
    avePro = Project / 3
    stuAvePro.append(avePro)
    print(f'project grade : {stuAvePro[i]}',end=' ')  
        
    
        