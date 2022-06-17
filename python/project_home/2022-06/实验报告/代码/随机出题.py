# 随机出题

import tkinter as tk

import random

def judge(a,b,s) -> int:
    if s == '+':
        return a + b
    elif s == '-':
        return a - b
    elif s == '*':
        return a * b
    elif s == '/':
        return a / b

   
root = tk.Tk()
root.geometry("400x400")

   
str = "+-*/" 
count = tk.IntVar()
right = tk.IntVar()
error = tk.IntVar()
sum = tk.IntVar()

first = tk.IntVar()
first.set(random.randint(1,9))

op = tk.StringVar()
op.set(random.choice(str))

second = tk.IntVar()
second.set(random.randint(1,9))

end = tk.IntVar()
end.set("")
input_end = tk.IntVar()
input_end.set("")

final_answer = []
final = tk.StringVar()
final.set(final_answer)

begin_show = tk.StringVar()
begin_show.set(f"{first.get()} {op.get()} {second.get()} = ")

def sue(event):
    end.set(judge(first.get(),second.get(),op.get())) 
    
    if input_end.get() == end.get():
        final_answer.append(f"{first.get()} {op.get()} {second.get()} = {input_end.get()}          OK")
    else:
        final_answer.append(f"{first.get()} {op.get()} {second.get()} = {input_end.get()}          NO") 
    final.set(final_answer)
    first.set(random.randint(1,9))
    op.set(random.choice(str))
    second.set(random.randint(1,9))   
    begin_show.set(f"{first.get()} {op.get()} {second.get()} = ")
    input_end.set("")
    
root.bind('<Return>', sue)   


# 左边显示框
label_left = tk.Label(root, textvariable= begin_show, width=15, height=1)
label_left.place(x=60, y=80)
# 输入答案框
label_right = tk.Entry(root, width=10, bg="gray", textvariable=input_end)
label_right.place(x = 185, y = 80)
# 左边显示题目框
listbox_left = tk.Listbox(root,height=8, width=33, listvariable=final)
listbox_left.place(x = 60, y = 120)


root.mainloop()
