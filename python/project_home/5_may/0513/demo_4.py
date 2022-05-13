import tkinter as tk

root = tk.Tk()

root.geometry("400x400")

imageobj = tk.PhotoImage(file="UI初稿.png")

label = tk.Label(root, image=imageobj)
label.pack()

root.mainloop()