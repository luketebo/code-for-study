from cgitb import text
import tkinter as tk
from tkinter import CENTER, ttk
from turtle import left, right, width

root = tk.Tk()
root.geometry('800x500')
root.title("背单词")

frame_1 = tk.Frame(root, width=800, height=600)
frame_1.pack()

frame1 = tk.Frame(frame_1, width=800, height=100)
frame1.pack(side='top')
frame2 = tk.Frame(frame_1, width=250, height=500)
frame2.pack(side='left')
frame3 = tk.Frame(frame_1, bg='green', width=550, height=500)
frame3.pack(side='right')


# frame1
text1 = tk.Label(frame1, text='不    背    单    词', font=('华文行楷', 30, 'italic'))
text1.pack()

# frame2

style_2 = ttk.Style()
style_2.configure("TButton", background="cyan", relief="flat")

button_1 = ttk.Button(frame2, text='查看单词', width=20)
button_2 = ttk.Button(frame2, text='记忆单词', width=20)
button_3 = ttk.Button(frame2, text='添加单词', width=20)
button_4 = ttk.Button(frame2, text='删除单词', width=20)
button_5 = ttk.Button(frame2, text='清空单词本', width=20)
button_6 = ttk.Button(frame2, text='退出单词本', width=20)
button_1.pack(padx=10, pady=10)
button_2.pack(padx=10, pady=10)
button_3.pack(padx=10, pady=10)
button_4.pack(padx=10, pady=10)
button_5.pack(padx=10, pady=10)
button_6.pack(padx=10, pady=10)

# frame3

frame_3_4 = tk.Frame(frame3, width=550, height=500, bg='cyan')
frame_3_4.pack(anchor=CENTER)



root.mainloop()