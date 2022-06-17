n = input()
new = []
print(n)
print("-----------")
for i in range(len(n)):
    a = chr(ord(n[i]) + 5)
    new.append(a)

print(new)