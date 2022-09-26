import tkinter as tk
from xml.dom.expatbuilder import theDOMImplementation

# 学生信息管理系统

root = tk.Tk()
root.geometry("400x400")

topMenu = tk.Menu(root)
cMenu_1 = tk.Menu(topMenu)
cMenu_1.add_command(label="New Text File")
cMenu_1.add_command(label="New File")
cMenu_1.add_command(label="New Windows")
topMenu.add_cascade(label="File", menu=cMenu_1)
topMenu.add_command(label="Edit")
topMenu.add_command(label="View")
topMenu.add_command(label="Help")
root['menu'] = topMenu


showMenu = tk.Menu(root)

showMenu.add_command(label="New")
showMenu.add_command(label="Open")



def showPopoutMenu(w, menu):
    def popout(event):
        menu.post(event.x + w.winfo_rootx(), event.y + w.winfo_rooty())
        w.update()
    w.bind('<Button-3>', popout)


showPopoutMenu(root, showMenu)

root.mainloop()

     