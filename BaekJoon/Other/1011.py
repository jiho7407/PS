import sys
input = sys.stdin.readline


def solve(a, b):
    cmd = b-a
    prm = 1
    while (prm*prm <= cmd):
        prm += 1
    prm -= 1
    if (cmd - prm*prm):
        return prm*2 + (cmd-prm*prm-1)//prm
    else:
        return prm*2-1


for TC in range(int(input())):
    x, y = map(int, input().split())
    print(solve(x, y))
