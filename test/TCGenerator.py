import os
from random import randint
import random

path = os.path.realpath("test/input.txt")
# print(path)

TC = 1
mxN = int(5000)
mxQ = int(1000)

# with open(path, "w") as file:
#     # file.write(f"{TC}\n")
#     for _ in range(TC):
#         N = randint(1, mxN)
#         Q = randint(1, mxQ)
#         file.write(f"{N} {Q}\n")
#         for i in range(3):
#             for j in range(N):
#                 file.write(f"{random.choice("abcdefghijklmnopqrstuvwxyz")}")
#             file.write("\n")
#         for i in range(Q):
#             L = randint(1, N)
#             R = randint(1, N)
#             if L > R:
#                 L, R = R, L
#             file.write(f"{L} {R}\n")

for _ in range(TC):
    N = randint(1, mxN)
    Q = randint(1, mxQ)
    print(f"{N} {Q}")
    for i in range(3):
        for j in range(N):
            print(f"{random.choice("abcdefghi")}", end="")
        print()
    for i in range(Q):
        L = randint(1, N)
        L = min(L, N)
        R = randint(1, N)
        R = min(R, N)
        if L > R:
            L, R = R, L
        print(f"{L} {R}")
