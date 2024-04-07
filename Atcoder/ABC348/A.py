N = int(input())
for i in range(N):
    if i % 3 == 2:
        print("x", end="")
    else:
        print("o", end="")
