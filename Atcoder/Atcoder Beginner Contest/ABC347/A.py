import sys
input = sys.stdin.readline
# sys.setrecursionlimit(10**6)


N, M = map(int, input().split())
lst = [*map(int, input().split())]
for i in range(N):
    if lst[i] % M == 0:
        print(lst[i]//M, end=" ")
