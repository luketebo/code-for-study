import tkinter as tk    

root = tk.Tk()
root.geometry("400x400")

topMenu = tk.Menu(root)

cMenu = tk.Menu(topMenu)
cMenu.add_command(label="北京")
cMenu.add_command(label="上海")
cMenu.add_command(label="重庆")
cMenu.add_command(label="广州")
cMenu.add_command(label="深圳")


topMenu.add_cascade(label="城市", menu=cMenu)
topMenu.add_command(label="修改", command=root.quit)
topMenu.add_command(label="退出", command=root.quit)

root['menu'] = topMenu

root.mainloop()