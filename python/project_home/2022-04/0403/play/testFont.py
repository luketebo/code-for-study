import turtle as T

# T.goto(0,0)
# T.penup()
# T.write("生")
# T.left(90)
# T.forward(50)
# T.write("死")
# T.done()

def write(n,x,y):
    fontList = []
    fontList = n.split(' ')
    count = len(fontList)
    print(count)
    print(fontList)
    T.goto(x,y)
    T.penup()
    for i in range(count):
        if i == 0:
            T.left(90)
        
        T.write(fontList[i])
        T.backward(85)
        
write("生 死 何 惧",0,0)
T.done()  