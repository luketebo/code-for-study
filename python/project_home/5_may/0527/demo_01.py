import tkinter as tk

root = tk.Tk()

root.geometry("400x400")

def new():
    win = tk.Toplevel()
    win.geometry("200x50")
    entry_1 = tk.Entry(win)
    entry_1.pack(side=tk.LEFT,padx=10) 
    button_2 = tk.Button(win, text="查找")
    button_2.pack(side=tk.LEFT,padx=10)

button_1 = tk.Button(root, text="查找", command=new)
button_1.pack()

text_1 = tk.Text()
text_1.pack()

root.mainloop()
