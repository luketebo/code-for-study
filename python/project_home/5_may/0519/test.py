import tkinter as tk


win = tk.Tk()
win.geometry("200x200")
list_new = tk.StringVar()
list_final = ["1", "2", "3", "4", "5"]
for item in list_final:
    print(item)        
list_new.set(list_final)
listbox_1 = tk.Listbox(win, width=20, listvariable=list_new)
listbox_1.pack()
win.mainloop()