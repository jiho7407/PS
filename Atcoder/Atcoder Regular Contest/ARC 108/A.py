import sys
input = sys.stdin.readline


def divs(N):
    divs = []
    for i in range(1, int(N**0.5)+1):
        if N % i == 0:
            divs.append(i)
    return divs


S, P = map(int, input().split())
for dv in divs(P):
    N, M = dv, P//dv
    if N+M == S:
        print("Yes")
        exit()
print("No")
