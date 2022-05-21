# 小猫小狗
from cProfile import label
import tkinter as tk    

root = tk.Tk()
root.geometry("400x400")



label = tk.Label(root, text="老师让小猫和小狗去背书，请问谁先背书", bg="red")
label.pack()

v = tk.IntVar()

# 单选框 
tk.Radiobutton(root, text="小猫", value=1, variable=v).pack()
tk.Radiobutton(root, text="小狗", value=2, variable=v).pack()
# 答案
global text_a, text_b 

# 显示函数
def show():
    print(v.get())
    if (v.get() == 2):
        text_a = "答对咯，小狗背书"
        label_1 = tk.Label(root, text=text_a)
        label_1.pack()
    else:
        text_b = "答错了，答案是小狗，因为'旺旺仙贝'(汪汪先背)"
        label_2 = tk.Label(root, text=text_b)
        label_2.pack()


# 按钮
buttonA = tk.Button(root, text="确定", bg="yellow", command=show)
buttonA.pack()
root.mainloop()