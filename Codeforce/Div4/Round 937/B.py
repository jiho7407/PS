import sys
input = sys.stdin.readline

for TC in range(int(input())):
    N = int(input())
    for i in range(N):
        for j in range(2):
            if i % 2:
                for k in range(N):
                    for m in range(2):
                        if k % 2:
                            print("#", end="")
                        else:
                            print(".", end="")
            else:
                for k in range(N):
                    for m in range(2):
                        if k % 2:
                            print(".", end="")
                        else:
                            print("#", end="")
            print()
