form tkinter import *
from pyparsing import replaceWith

root = Tk()
root.title("test")
root.geometry("350x280")

lb1 = Label(root, text="出发地")
lb1.place(relx=0.03, rely=0.1, relwidth=0.5, relheight=0.1)

inp1 = Entry(root)
inp1.place(relx=0.4, rely=0.1, relwidth=0.4, relheight=0.1)

lb2 = Label(root, text="目的地")
lb2.place(relx=0.03, rely=0.25, relwidth=0.5, relheight=0.1)
inp2 = Entry(root)
inp2.place(relx=0.4, rely=0.25, relwidth=0.4, relheight=0.1)
root.mainloop()