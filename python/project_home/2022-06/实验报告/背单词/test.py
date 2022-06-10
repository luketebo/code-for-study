from distutils.log import info
from threading import get_ident
from turtle import width
import ttkbootstrap as ttk
from ttkbootstrap.constants import *

root = ttk.Window()
root.geometry("700x450")
root.title("不背单词")

word = {"good":"好的", "demo":"案例"} # 单词

frame_1 = ttk.Frame(root, bootstyle="info", width=800, height=100)
frame_1.pack(side="top")
frame_2 = ttk.Frame(root, width=220, height=400)
frame_2.pack(side="left")
frame_3 = ttk.Labelframe(root, bootstyle=SUCCESS, width=580, height=400)
frame_3.pack(side='right', padx=10, pady=10)
frame_3.pack_propagate(0)

# frame_3_1  查看单词
frame_3_1 = ttk.Frame(frame_3, width=580, height=100)
# frame_3_1.pack()
frame_3_1.pack_propagate(0)

label_3_1 = ttk.Label(frame_3_1, text="Show Menu", font=("宋体", 15))
label_3_1.pack(side="top", padx=10, pady=10)

for key, value in word.items():
    label_3_2 = ttk.Label(frame_3_1, text=f"{key}: {value}", font=("微软雅黑", 10))
    label_3_2.pack(side="left", padx=10, pady=10)

# frame_3_2  记忆单词
frame_3_2 = ttk.Frame(frame_3, width=580, height=100)
frame_3_2.pack()
frame_3_2.pack_propagate(0)


label_3_2_1 = ttk.Label(frame_3_2, text="Remember Words", font=("宋体", 15))
label_3_2_1.pack(side="top", padx=10, pady=10)

label_3_2_2 = ttk.Label(frame_3_2, text="单词", font=("微软雅黑"))
label_3_2_2.pack(side="left",padx=5, pady=10)

label_3_2_3 = ttk.Label(frame_3_2, text="hhhh", font=("微软雅黑"), bootstyle="inverse",width=10)
label_3_2_3.pack(side="left", padx=10, pady=10)

label_3_2_4 = ttk.Label(frame_3_2, text="翻译", font=("微软雅黑"))
label_3_2_4.pack(side="left",padx= 10, pady=10)

entry_3_2_1 = ttk.Entry(frame_3_2, width=10)
entry_3_2_1.pack(side="left", padx=10, pady=10)

button_3_2_1 = ttk.Button(frame_3_2, text="提交", bootstyle="success")
button_3_2_1.pack(side="left", padx=10, pady=10)

frame_3_2_1 = ttk.LabelFrame(frame_3_2, width=580, height=50)
frame_3_2_1.pack(side="bottom", padx=10, pady=10)
frame_3_2_1.pack_propagate(0)

# function
def show():
    frame_3_1.pack()

def remember():
    frame_3_1.pack_forget()

def add():
    pass

def delete():
    pass

def clear():
    pass

# frame_1
label_1 = ttk.Label(frame_1, text="不    背    单    词", font=("宋体",25))
label_1.pack()

# frame_2

button_1 = ttk.Button(frame_2, text='查看单词', width=20, command=show)
button_2 = ttk.Button(frame_2, text='记忆单词', width=20, command=remember)
button_3 = ttk.Button(frame_2, text='添加单词', width=20, command=add)
button_4 = ttk.Button(frame_2, text='删除单词', width=20, command=delete)
button_5 = ttk.Button(frame_2, text='清空单词本', width=20, command=clear)
button_6 = ttk.Button(frame_2, text='退出单词本', width=20, command=quit)
button_1.pack(padx=10, pady=10)
button_2.pack(padx=10, pady=10)
button_3.pack(padx=10, pady=10)
button_4.pack(padx=10, pady=10)
button_5.pack(padx=10, pady=10)
button_6.pack(padx=10, pady=10)

# frame_3


root.mainloop()
