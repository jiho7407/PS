from random import randint

N = randint(10000, 50000)

lst = []
for i in range(N):
    lst.append(randint(-1000000000, -10))

# print(N)
# print(*lst)

with open("D:/Programming-D/PS/test/input.txt", "w") as file:
    file.write(str(N) + "\n")
    file.write(" ".join(map(str, lst)))
