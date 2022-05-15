import tkinter

root = tkinter.Tk()

win_1 = tkinter.Label(root, text="暮冬时烤雪", anchor="w")
win_2 = tkinter.Label(root, text="迟夏写长信", anchor="e")
win_3 = tkinter.Label(root, text="早春不过一棵树", anchor="center")
win_1.pack(side="left")
win_2.pack(side="left")
win_3.pack(side="left")

root.mainloop()