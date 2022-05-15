from tkinter import *


root = Tk()
root.geometry("400x400")

def add():
    re.delete(0, END)
    add_1 = int(op1.get())
    add_2 = int(op2.get())
    re.insert(INSERT, add_1 + add_2)
    
op1 = Entry(root, width=5, relief="groove")
op1.grid(row = 0, pady = 20)
Label(root, text="+").grid(row = 0, column = 1)
op2 = Entry(root, width=5, relief="groove")
op2.grid(row = 0, column = 2)
Label(root, text="=").grid(row = 0, column = 3)
re = Entry(win, width=5, relief="groove")
re.grid(row = 0, column = 4)
Button(root, text="计算", command=add, relief="groove").grid(row=1, columnspan=5, ipadx=10)
root.mainloop()