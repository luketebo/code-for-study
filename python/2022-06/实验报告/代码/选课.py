# 课程选择

import tkinter as tk    

root = tk.Tk()
root.geometry("400x400")

list_course = ["Python", "Java", "C++", "English", "Math", "Chinese"]
list_course_new = []

var_course = tk.StringVar()
var_course.set(list_course)

var_course_new = tk.StringVar()
    

label_1 = tk.Label(root, text="待选课程", bg="red").place(x=100, y= 50, anchor= 'nw')
label_2 = tk.Label(root, text="已选课程", bg="red").place(x= 300, y = 50, anchor= 'ne')


listbox_1 = tk.Listbox(root, width=20, height=10, bg="yellow", listvariable=var_course)
listbox_1.place(x= 50, y= 100, anchor= 'nw')

listbox_2 = tk.Listbox(root, width=20, height=10, bg="yellow", listvariable=var_course_new)
listbox_2.place(x = 350, y= 100, anchor= 'ne')


def select():
    list_course_new.append(listbox_1.get(listbox_1.curselection()))
    var_course_new.set(list_course_new)

def clear():
    list_course_new.remove(listbox_2.get(listbox_2.curselection()))
    var_course_new.set(list_course_new)
    
button_1 = tk.Button(root, text=">>>", bg="green", command=select).place(x= 184, y= 140, anchor= 'nw')
button_2 = tk.Button(root, text="<<<", bg="green", command=clear).place(x= 184, y= 200, anchor= 'nw')
  
    
root.mainloop()