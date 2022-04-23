address_list = {}

print("欢迎使用通信录")
print("1. 添加联系人")
print("2. 查看通讯录")
print("3. 删除联系人")
print("4. 修改联系人信息")
print("5. 查找联系人")
print("6. 退出通信录")
print("7. test")
while True:
    method = int(input("请输入操作序号："))
    if method == 1:
        name = input("请输入姓名：")
        phone = input("请输入电话：")
        email = input("请输入邮箱：")
        address = input("请输入地址：")
        address_list.update({name:{'phone':phone,'email':email,'address':address}})
        print("保存成功") 
    elif method == 2:
        print(address_list)
    elif method == 3:
        name = input("请输入姓名：")
        if name in address_list.keys:
            address_list.pop(name)
            print("删除成功")
        else:
            print("没有这个人")
        
    elif method == 4:
        name = input("请输入姓名：")
        if name in address_list.keys:
            address_list[name]['phone'] = input("请输入电话：")
            address_list[name]['email'] = input("请输入邮箱：")
            address_list[name]['address'] = input("请输入地址：")
            print("修改成功")
        else:
            print("没有这个人")
        
    elif method == 5:
        name = input("请输入姓名：")
        if name in address_list.keys:
            print("姓名：{0}".format(name))
            print("电话：{0}".format(address_list[name]['phone']))
            print("邮箱：{0}".format(address_list[name]['email']))
            print("地址：{0}".format(address_list[name]['address']))
        else:
            print("没有这个人")
    elif method == 6:
        for name in address_list.keys:
            print(name)
    else:
        break  