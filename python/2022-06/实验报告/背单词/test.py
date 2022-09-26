from distutils.log import info
from threading import get_ident
from turtle import bgcolor, width
import ttkbootstrap as ttk
from ttkbootstrap.constants import *

root = ttk.Window()
root.geometry("700x450")
root.title("不背单词")

word = {} # 单词

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

# for key, value in word.items():
#     label_3_2 = ttk.Label(frame_3_1, text=f"{key}: {value}", font=("微软雅黑", 10))
#     label_3_2.pack(side="left", padx=10, pady=10)

# frame_3_2  记忆单词
frame_3_2 = ttk.Frame(frame_3, width=580, height=400)
# frame_3_2.pack()
frame_3_2.pack_propagate(0)

import random
label_3_2_word_1 = ttk.StringVar()
# if word == {}:
    # label_3_2_word_1.set("")
label_3_2_word_2 = ttk.StringVar()

label_3_2_1 = ttk.Label(frame_3_2, text="Remember Words", font=("宋体", 15))
label_3_2_1.place(x = 150, y = 0)

label_3_2_2 = ttk.Label(frame_3_2, text="单词", font=("微软雅黑"))
label_3_2_2.place(x = 20, y = 50 )

label_3_2_3 = ttk.Label(frame_3_2, textvariable=label_3_2_word_1, font=("微软雅黑"), bootstyle="success",width=10)
label_3_2_3.place(x = 80, y = 50)

label_3_2_4 = ttk.Label(frame_3_2, text="翻译", font=("微软雅黑"))
label_3_2_4.place(x = 220, y = 50)

entry_3_2_1 = ttk.Entry(frame_3_2, width=10, textvariable=label_3_2_word_2)
entry_3_2_1.place(x = 280, y =50)

frame_3_2_1 = ttk.LabelFrame(frame_3_2, width=450, height=250, bootstyle=SUCCESS)
frame_3_2_1.place(x= 20, y = 100)

def remember_word():
    one = label_3_2_word_1.get()  # key
    two = str(label_3_2_word_2.get())
    print(one)
    print(two)
    if word[one] == two:
        label_3_2_5 = ttk.Label(frame_3_2_1, text=f"{one} : {two} 记忆成功", font=("微软雅黑", 10)) 
        label_3_2_5.pack(padx=10, pady=10)
        a,b = random.choice(list(word.items()))
        label_3_2_word_1.set(a)
        label_3_2_word_2.set("")
    else:
        label_3_2_5 = ttk.Label(frame_3_2_1, text=f"{one} : {two} 记忆错误", font=("微软雅黑", 10)) 
        label_3_2_5.pack(padx=10, pady=10)

button_3_2_1 = ttk.Button(frame_3_2, text="提交", bootstyle="success", command=remember_word)
button_3_2_1.place(x = 400, y = 50)

# frame_3_2_1 = ttk.LabelFrame(frame_3_2, width=450, height=250, bootstyle=SUCCESS)
# frame_3_2_1.place(x= 20, y = 100)


# label_3_2_1_1 = ttk.Label(frame_3_2_1, text="展示框")
# label_3_2_1_1.pack()

# frame_3_3  添加单词
frame_3_3 = ttk.Frame(frame_3, width=580, height=400)
# frame_3_3.pack()
frame_3_3.pack_propagate(0)


label_3_3_1 = ttk.Label(frame_3_3, text="Add Words", font=("宋体", 15))
label_3_3_1.pack(side="top", padx=10, pady=10)

label_word_1 = ttk.StringVar()
label_word_2 = ttk.StringVar()

label_3_3_2 = ttk.Label(frame_3_3, text="单词", font=("微软雅黑"))
label_3_3_2.pack(side="left",padx=5, pady=10, anchor='nw')

label_3_3_3 = ttk.Entry(frame_3_3, width=10, textvariable=label_word_1)
label_3_3_3.pack(side="left", padx=10, pady=10, anchor='nw')

label_3_3_4 = ttk.Label(frame_3_3, text="翻译", font=("微软雅黑"))
label_3_3_4.pack(side="left",padx= 10, pady=10, anchor='nw')

entry_3_3_1 = ttk.Entry(frame_3_3, width=10, textvariable=label_word_2)
entry_3_3_1.pack(side="left", padx=10, pady=10, anchor='nw')



def submit():
    if label_word_1.get() != "":
        word[label_word_1.get()] = label_word_2.get()
        
    label_word_1.set("")
    label_word_2.set("")
    # label_3_3_5 = ttk.Label(frame_3_3, text=f"{label_3_3_3.get()} : {entry_3_3_1.get()} 添加成功", font=("微软雅黑", 10))
    # label_3_3_5.pack(padx=10, pady=10)

button_3_3_1 = ttk.Button(frame_3_3, text="提交", bootstyle="success", command=submit)
button_3_3_1.pack(side="right", padx=10, pady=10, anchor='nw')

# frame_3_3_1 = ttk.LabelFrame(frame_3_3, width=580, height=50)
# frame_3_3_1.pack(side="bottom", padx=10, pady=10)
# frame_3_3_1.pack_propagate(0)

# label_3_3_1_1 = ttk.Label(frame_3_3_1)
# label_3_3_1_1.pack()

# frame_3_4 清除单词

frame_3_4 = ttk.Frame(frame_3, width=580, height=100)
# frame_3_4.pack()
frame_3_4.pack_propagate(0)

## 创建label

label_3_4_word_1 = ttk.StringVar()

label_3_4_1 = ttk.Label(frame_3_4, text="请输入要删除的单词", font=("宋体", 15))
label_3_4_1.pack(side="left", padx=10, pady=10)

entry_3_4_1 = ttk.Entry(frame_3_4, width=10, textvariable=label_3_4_word_1)
entry_3_4_1.pack(side="left", padx=10, pady=10)


def delete_word():
    one = label_3_4_word_1.get()
    del word[one]
    

button_3_4_1 = ttk.Button(frame_3_4, text="提交", bootstyle="success", command=delete_word)
button_3_4_1.pack(side="left", padx=10, pady=10)
# frame_3_5 清空单词
frame_3_5 = ttk.Frame(frame_3, width=580, height=100)
frame_3_5.pack_propagate(0)

label_3_5_1 = ttk.Label(frame_3_5, text="单词已清空", font=("宋体", 15))
label_3_5_1.pack(side="left", padx=10, pady=10)

label_3_2 = ttk.Label(frame_3_1, font=("微软雅黑", 10))

# function
def show():
    frame_3_1.pack()
    for key, value in word.items():
        # label_3_2 = ttk.Label(frame_3_1, text=f"{key}: {value}", font=("微软雅黑", 10))
        label_3_2['text'] = f"{key}: {value}"
        label_3_2.pack(side="left", padx=10, pady=10)
    # if word == {}:
    #     label_3_2 = ttk.Label(frame_3_1, text="暂无单词", font=("微软雅黑", 10))
    #     label_3_2.pack(side="left", padx=10, pady=10)
    frame_3_2.pack_forget()
    frame_3_3.pack_forget()
    frame_3_4.pack_forget()
    frame_3_5.pack_forget()

def remember():
    frame_3_1.pack_forget()
    frame_3_2.pack()
    a,b = random.choice(list(word.items()))
    print(a, b)
    # remember_word()
    if word != {}:
        label_3_2_word_1.set(a)
    else:
        label_3_2_word_1.set("暂无单词")
    frame_3_3.pack_forget()
    frame_3_4.pack_forget()
    frame_3_5.pack_forget()

def add():
    frame_3_1.pack_forget()
    frame_3_2.pack_forget()
    frame_3_3.pack()
    frame_3_4.pack_forget()
    frame_3_5.pack_forget()

def delete():
    frame_3_1.pack_forget()
    label_3_2["text"] = ""
    frame_3_2.pack_forget()
    frame_3_3.pack_forget()
    frame_3_4.pack()
    frame_3_5.pack_forget()

def clear():
    frame_3_1.pack_forget()
    frame_3_2.pack_forget()
    frame_3_3.pack_forget()
    frame_3_4.pack_forget()
    word.clear()
    frame_3_5.pack()
    label_3_2['text'] = "单词已清空"

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
