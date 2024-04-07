import sys
input = sys.stdin.readline

N = int(input())
lst = []
for i in range(N):
    cmd, a = map(int, input().split())
    if cmd == 1:
        lst.append(a)
    else:
        print(lst[a*(-1)])