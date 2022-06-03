import tkinter as tk

def showPopoutMenu(w, menu):
    def popout(event):
        # winfo_* 可以获取小组件的信息
        menu.post(event.x + w.winfo_rootx(), event.y + w.winfo_rooty())
        w.update()
    w.bind('<Button-3>', popout)
    
    
root = tk.Tk()
root.geometry("400x400")

menu = tk.Menu(root)
menu.add_cascade(label="复制")
menu.add_cascade(label="粘贴")
showPopoutMenu(root, menu)

root.mainloop()
