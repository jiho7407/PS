import sys
# sys.setrecursionlimit(10**6)
input = sys.stdin.readline

S = "wbwbwwbwbwbw"
W, B = map(int, input().split())
for i in range(12):
    w, b = 0, 0
    for j in range(W+B):
        if (S[(i+j) % 12] == "w"):
            w += 1
        else:
            b += 1
    if w == W and b == B:
        print("Yes")
        sys.exit()
print("No")
