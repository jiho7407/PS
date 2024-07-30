lst = []

for i in range(5):
    for j in range(i+1, 5):
        lst.append((1 << i | 1 << j))

print(lst)
