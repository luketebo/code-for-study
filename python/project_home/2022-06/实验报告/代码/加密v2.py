num = input()
num_asc = ''
sum_num = 0
for i in range(6):
    # num_asc.append(ord(num[i]))
    num_asc += str(ord(num[i]))
    sum_num += ord(num[i])
# 把ascii进行拼接
unum_asc = num_asc[::-1]
unum_asc = int(unum_asc)
pwd = unum_asc + sum_num
print(pwd)