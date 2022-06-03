import random
list = []
for i in range(6):
    num = random.randint(1,33)
    while True:
        if num in list:
            num = random.randint(1,33)
        else: break
    list.append(num)
list.sort()
print(list)
list.append(random.randint(1,16))
print(list)  ## rewarding
def rewarding(list,list_new):
    count = 0
    count_last = 0
    print(list)
    print(list_new)
    for i in range(6):
        if list[i] == list_new[i]:
            count += 1
    if list[6] == list_new[6]:
        count_last += 1 
             
    if count == 6 and count_last == 1:
        print("one rewarding 5000000$")
    elif count == 6:
        print("two rewarding 100000$")
    elif count == 5 and count_last == 1:
        print("third rewarding 3000$")
    elif (count == 4 and count_last == 1) or count == 5:
        print("four rewarding 200$")
    elif (count == 3 and count_last == 1) or count == 4:
        print("five rewarding 10$")
    elif count >= 2 and count_last == 1:
        print("six rewarding 5$")   
print("1. machine create auto 2. choose for you self")
choose = int(input())
if choose == 1:
    list_mac = []
    for i in range(6):
        num_mac = random.randint(1,33)
        while True:
            if num_mac in list_mac:
                num_mac = random.randint(1,33)
            else:
                break 
        list_mac.append(num_mac)    
    list_mac.sort()
    list_mac.append(random.randint(1,16))    
    print(f"the machine choose num \n{list_mac}")
    rewarding(list,list_mac)
elif choose == 2:
    list_self = []
    for i in range(6):
        num_self = int(input("input the five number between 1 - 30 "))
        while True:
            if num_self in list_self:
                num_self = int(input("input the number again "))
            else:
                break
        list_self.append(num_self)
    list_self.sort()
    num_self_last = int(input("input the last number "))
    list_self.append(num_self_last)
    rewarding(list,list_self)
