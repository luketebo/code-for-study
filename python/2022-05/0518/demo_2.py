import tkinter as tk

root = tk.Tk()

root.geometry("400x400")

list1 = tk.Listbox(root)
list1.pack()

ListTable = ["重庆", "北京", "上海", "广州", "深圳", "香港", "澳门"]

for i in ListTable:
    list1.insert('end', i)
    
    
root.mainloop()