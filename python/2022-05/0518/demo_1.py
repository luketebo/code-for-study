import tkinter as tk
from PIL import Image, ImageTk

root = tk.Tk()

imageobj_1 = tk.PhotoImage(file="1.png")
imageobj_2 = ImageTk.PhotoImage(file="2.jpg")


label_1 = tk.Label(root, image=imageobj_1)
label_2 = tk.Label(root, image=imageobj_2)

label_1.pack()
label_2.pack()

root.mainloop()