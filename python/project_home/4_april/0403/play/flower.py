import turtle
turtle.shape('turtle')
turtle.dot(30)  ## 画点
turtle.speed(0)  ## 速度
turtle.delay(0)   ## 延迟
turtle.fillcolor('navy')  ## 填充颜色
turtle.begin_fill()  ## 开始填充
for x in range(12):
    # print(f"first : {x}\n")
    for x in range(10):
        # print(f"second : {x}\n")
        turtle.backward(20)  ## 后退
        turtle.dot(20)  ## 画点
        turtle.left(37)     ## 左转
        turtle.forward(20)  ## 向前
        turtle.dot(30)  
        turtle.color('blue')   ## 颜色
        turtle.backward(30)
    turtle.forward(20)    ## 向前
    for x in range(10):
        # print(f"third : {x}\n")
        turtle.backward(10)
        turtle.dot(20)
        turtle.left(90)
        turtle.forward(50)
        turtle.dot(30)
        turtle.color('yellow')
        turtle.backward(30)
    turtle.forward(20)
    for x in range(10):
        # print(f"four : {x}\n")
        turtle.backward(20)
        turtle.dot(20)
        turtle.left(50)
        turtle.forward(10)
        turtle.dot(30)
        turtle.color('green')
        turtle.backward(30)
turtle.end_fill()   ## 结束填充
turtle.done()