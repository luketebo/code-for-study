import tkinter as tk

root = tk.Tk()

win_1 = tk.Label(root, text="暮冬时烤雪",justify="left")
win_2 = tk.Label(root, text="Hello World", justify="left")
win_3 = tk.Label(root, text="hao", justify="left")
win_1.pack()
win_2.pack()
win_3.pack()

root.mainloop()