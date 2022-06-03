import tkinter as tk
import tkinter.messagebox as msg

root = tk.Tk()
root.geometry("400x400")

def showinfo():
    msg.showinfo("提示", "好久不见，欢迎回归")
    
def showwarning():
    msg.showwarning("警告", "你已经被监控")
    
def showerror():
    msg.showerror("错误", "写错了")
    
def showAskquestion():
    msg.askquestion("问题", "发生甚么事了？")
    
tk.Button(root, text="showinfo", command=showinfo, width=15).pack()
tk.Button(root, text="showwarning", command=showwarning, width=15).pack()
tk.Button(root, text="showerror", command=showerror, width=15).pack()
tk.Button(root, text="showAskquestion", command=showAskquestion, width=15).pack()

root.mainloop()
