# 随机抽取大崽种
from ast import Raise
import tkinter as tk
from tkinter import BOTH, RAISED, TOP, ttk
import random

root = tk.Tk()
root.geometry("400x400")

frame_1 = tk.Frame(root, relief=RAISED)
frame_1.pack(side=TOP,fill=BOTH)

label_1 = tk.Label(frame_1, text="选择会员：")
label_1.pack(side=tk.LEFT, padx=10, pady=10)

value = tk.StringVar()
value.set("38元银卡会员")
values = ["38元银卡会员", "68元金卡会员", "128元白金卡会员"]

def extract():
    i = random.randint(0, 2)
    value.set(values[i])

def show():
    text = value.get()
    label_1 = tk.Label(root, text=f"抽取结果：{text}")
    label_1.pack()
    

combobox_1 = ttk.Combobox(frame_1, textvariable=value, values=values)
combobox_1.pack(side=tk.LEFT, padx=10, pady=10)

button_1 = tk.Button(frame_1, text="抽取", width=10, command=extract)
button_1.pack(side=tk.LEFT, padx=10, pady=10)

button_2 = tk.Button(root, text="提交", width=10, command=show)
button_2.pack(side=tk.TOP, pady=100)


root.mainloop()