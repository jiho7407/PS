import sys
input = sys.stdin.readline

N, L, R = map(int, input().split())
lst = [*map(int, input().split())]

for cmd in lst:
    if cmd < L:
        print(L, end=' ')
    elif cmd > R:
        print(R, end=' ')
    else:
        print(cmd, end=' ')
