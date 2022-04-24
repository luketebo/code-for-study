list = []
list_word = []

print("input the word no will break")
while True:
    word = input()
    if word == 'no':
        break
    list.append(word)
        
word = {}

for i in range(len(list)):
    count = 0
    for j in range(len(list)):
        if list[i] == list[j]:
            count += 1
    if list[i] not in word.values():  
        word.update({list[i]:count})
    
print(word)