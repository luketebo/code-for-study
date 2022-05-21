from operator import indexOf
import tkinter as tk

root = tk.Tk()
root.geometry("400x400")

label_1 = tk.Label(root, text="测试你性格有几面\n当你看不惯别人的行为时,你会直接指出吗?", bg="red")
label_1.pack()

v = tk.IntVar()

tk.Radiobutton(root, text="一定会", value=1, variable=v, indicatoron=False, width=25, pady=3).pack(padx="0.1i", pady="0.1i")
tk.Radiobutton(root, text="很可能会", value=2, variable=v, indicatoron=False, width=25, pady=3).pack(padx="0.1i", pady="0.1i")
tk.Radiobutton(root, text="偶尔会", value=3, variable=v, indicatoron=False, width=25, pady=3).pack(padx="0.1i", pady="0.1i")
tk.Radiobutton(root, text="绝不会", value=4, variable=v, indicatoron=False, width=25, pady=3).pack(padx="0.1i", pady="0.1i")


def show():
    if (v.get() == 1):
        tk.Label(root, text="不知道").pack()
    elif (v.get() == 2):
        tk.Label(root, text="gg").pack()
    elif (v.get() == 3):
        tk.Label(root, text="ooooo").pack()
    else:
        tk.Label(root, text="优之极额达").pack() 




button_1  = tk.Button(root, text="提交", bg="yellow", command=show)
button_1.pack()
root.mainloop()