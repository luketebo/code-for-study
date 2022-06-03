import tkinter as tk

root = tk.Tk()

root.geometry("400x400")

exit_win = tk.Label(root, text="确定退出窗口吗？", width=20, height=5, anchor="center")
exit_win.pack()

exit_but = tk.Button(root, text="果断退出", command=root.quit, anchor="ne", bg="purple", padx="10", pady="10")
think_but = tk.Button(root, text="我再想想", command=root.destroy, anchor="nw", bg="green", padx="10", pady="10")
exit_but.pack()
think_but.pack()

root.mainloop()