import tkinter as tk

root = tk.Tk()

root.geometry("400x400")

topMenu = tk.Menu(root)
topMenu.add_command(label="新建")
# topMenu.add_command(label="文件")

secondMenu = tk.Menu(topMenu)
secondMenu.add_command(label="打开")

topMenu.add_cascade(label="文件", menu=secondMenu)

root['menu'] = topMenu()

root.mainloop()
