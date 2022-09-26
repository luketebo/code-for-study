# 登录
import tkinter as tk
import tkinter.messagebox as tkmb

root = tk.Tk()

root.geometry("400x400")

tk.Label(root,text="用户名:").place(x=100, y=150)
tk.Label(root, text="密码:").place(x=100, y=190)
# 用户输入框
val_use_name = tk.StringVar()
entry_use_name = tk.Entry(root, textvariable=val_use_name)
entry_use_name.place(x=160, y=150)
# 密码
val_use_pwd = tk.StringVar()
entry_use_pwd = tk.Entry(root, textvariable=val_use_pwd, show="*")
entry_use_pwd.place(x=160, y=190)

count = tk.IntVar()
count.set(0)

# 登录函数
def login():     
    use_name = val_use_name.get()
    use_pwd = val_use_pwd.get()
    if use_name == "user1" and use_pwd == "123":
        tkmb.showinfo(title="welcome", message="欢迎登录")
    else:
        tkmb.showinfo(title="error", message="账号或密码错误")
        count.set(count.get()+1)
    if count.get() >= 3:
        bt_login["state"] = "disable"
    


# 登录
bt_login = tk.Button(root, text="登录", command=login, )
bt_login.place(x=200, y=230)



root.mainloop()
   
