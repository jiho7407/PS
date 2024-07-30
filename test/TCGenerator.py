from random import randint
import random

TC = 5
mxN = int(1000)
mxA = 2

with open("D:/Programming-D/PS/test/input.txt", "w") as file:
    file.write(f"{TC}\n")
    for _ in range(TC):
        N = randint(1, mxN)
        file.write(f"{N}\n")
        for i in range(N):
            file.write(f"{randint(1, mxA)} ")
        file.write("\n")
