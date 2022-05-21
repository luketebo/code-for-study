# 注册
import tkinter as tk    

root = tk.Tk()
root.geometry('300x300')

student_id = tk.StringVar()
student_name = tk.StringVar()
student_sex = tk.StringVar()
student_hobby = tk.StringVar()
student_five = tk.StringVar()

frame_1 = tk.Frame(root, height=200)
frame_1.pack(side="top", fill='x')

frame_2 = tk.Frame(root, height=100)
frame_2.pack(side="top", fill='x')

frame_3 = tk.Frame(frame_1, height=200, width=150)
frame_3.pack(side="left")
frame_4 = tk.Frame(frame_1,  height=200, width=150)
frame_4.pack(side="right")

label_1 = tk.Label(frame_3, text="学号", width=15)
label_1.pack(padx=10, pady=10, anchor='center')

input_1 = tk.Entry(frame_4, width=25, textvariable=student_id)
input_1.pack(padx=10, pady=10, anchor='center')

label_2 = tk.Label(frame_3, text="姓名", width=15)
label_2.pack(padx=10, pady=10, anchor='center')

input_2 = tk.Entry(frame_4, width=25, textvariable=student_name)
input_2.pack(padx=10, pady=10, anchor='center')

label_3 = tk.Label(frame_3, text="性别", width=15)
label_3.pack(padx=10, pady=10, anchor='center')

input_3 = tk.Entry(frame_4, width=25, textvariable=student_sex)
input_3.pack(padx=10, pady=10, anchor='center')

label_4 = tk.Label(frame_3, text="爱好", width=15)
label_4.pack(padx=10, pady=10, anchor='center')

input_4 = tk.Entry(frame_4, width=25, textvariable=student_hobby)
input_4.pack(padx=10, pady=10, anchor='center')

label_5 = tk.Label(frame_3, text="第五项", width=15)
label_5.pack(padx=10, pady=10, anchor='center')

input_5 = tk.Entry(frame_4, width=25, textvariable=student_five)
input_5.pack(padx=10, pady=10, anchor='center')

def submit():
    win = tk.Toplevel()
    win.geometry("200x200")
    list_new = tk.StringVar()
    list_final = [student_id.get(), student_name.get(), student_sex.get(), student_hobby.get(), student_five.get()]
    for item in list_final:
        print(item)        
    list_new.set(list_final)
    listbox_1 = tk.Listbox(win, width=20, listvariable=list_new)
    listbox_1.pack()
    win.mainloop()


button_1 = tk.Button(frame_2, text="提交", width=10, command=submit)
button_1.pack(anchor='n', padx=10, pady=30)



root.mainloop()