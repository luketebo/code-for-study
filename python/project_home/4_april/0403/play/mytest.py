import turtle as T

T.speed(0)
T.delay(0)

for x in range(2):
    for i in range(14):
        T.goto(0, 0)
        T.penup()
        T.backward(60)
        T.color('yellow')
        T.dot(25)
        T.left(47)
        T.forward(20)
        T.dot(15)

        T.backward(20)
    T.forward(60)

for x in range(6):
    for i in range(5):
        T.goto(0, 0)
        T.penup()
        T.backward(87)
        T.color('red')
        T.dot(25)
        T.left(47)
        T.forward(20)
        T.dot(15)

        T.backward(20)
    T.forward(60)

for x in range(3):
    for i in range(7):
        T.goto(0, 0)
        T.penup()
        T.backward(115)
        T.color('green yellow')
        T.dot(35)
        T.left(57)
        T.forward(20)
        T.dot(15)

        T.backward(20)
    T.forward(60)

for x in range(1):
    for i in range(24):
        T.goto(0, 0)
        T.penup()
        T.color('DeepPink2')
        T.backward(150)
        T.dot(45)
        T.left(67)
        T.forward(20)
        T.dot(15)
        T.backward(20)
    T.forward(60)


def writeNew(n, x, y):
    T.color('black')
    fontList = []
    # fontList = n.split(' ')
    count = len(fontList)
    T.goto(x, y)
    T.penup()
    T.write(n, )
    for i in range(count):
        T.write(fontList[i], font=('Times', 100, 'bold'))
        T.backward(85)


def write(n, x, y):
    T.color('black')
    fontList = []
    fontList = n.split(' ')
    count = len(fontList)
    T.goto(x, y)
    T.penup()
    for i in range(count):
        if i == 0:
            T.seth(90)
        T.write(fontList[i], font=('BRUSHSCI.TTF', '50', 'bold'))
        T.backward(85)


T.penup()
T.goto(0, 0)

write('奠', -32, -32)
# T.right(90)
T.goto(0, 0)
write('生 亦 何 欢', -300, 140)
T.right(90)
write('死 亦 何 苦', 220, 140)
T.right(90)
writeNew('--------by yang', 200, -200)
T.hideturtle()
T.done()
