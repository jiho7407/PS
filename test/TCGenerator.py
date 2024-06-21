from random import randint
import random

N = randint(5, 10)
T = randint(5, 10)

with open("D:/Programming-D/PS/test/input.txt", "w") as file:
    file.write(f"{N}\n")
    for i in range(N):
        file.write(f"{randint(0, 1)} ")
    file.write("\n")
    file.write(f"{T}\n")
    for i in range(T):
        op = randint(1, 2)
        a = randint(1, N)
        b = randint(a, N)
        file.write(f"{op} {a} {b}\n")
