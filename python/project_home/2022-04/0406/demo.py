print("-----------------------welcome to the friend system--------------------")
print("1. add a friend  2. delete a friend  3. edit a friend  4. show a friend")
print("5. exit")
friend = []
while(1):
    print("input you choice")
    n = int(input())
    if n == 1:
        print("adding a friend")
        name = input("input the friend name")
        print(name)
        friend.append(name)
        print(friend)
    elif n == 2:
        print("deleting the friend ")
        name = input("input the friend name")
        if name in friend :
            friend.remove(name)
            print("success!!!")
        else:
            print("name not exit")
    elif n == 3:
        print("editing the friend")
        name = input("input the friend name")
        if name in friend :
            n = friend.index(name)
            name = input("input the new name")
            friend[n] = name
            print("success!!!")
        else:
            print("name not exit")
    elif n == 4:
        print(friend)
    elif n == 5:
        print("see you latter")
        break