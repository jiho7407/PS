from random import randint

N = 20

with open("D:/Programming-D/PS/test/input.txt", "w") as file:
    file.write(f"{N}\n")
    for i in range(10):
        file.write(f"1 {randint(1, 100)}\n")
    for i in range(10):
        tmp = randint(3, 5)
        if tmp == 3:
            tmp -= 1
        L = randint(1, 10)
        R = randint(L, 10)

        if tmp != 5:
            file.write(f"{tmp} {L} {R} {randint(1, 100)}\n")
        else:
            file.write(f"{tmp} {L} {R} {randint(1, R-L+1)}\n")
