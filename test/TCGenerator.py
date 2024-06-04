from random import randint

N = randint(1, 5)
C = randint(1, 20)
W = randint(1, 10)
lst = [randint(1, 20) for _ in range(N)]

with open("D:/Programming-D/PS/test/input.txt", "w") as file:
    file.write(str(N) + " " + str(C) + " " + str(W) + "\n")
    for i in lst:
        file.write(str(i) + "\n")
