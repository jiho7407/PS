import sys
# sys.setrecursionlimit(10**6)
input = sys.stdin.readline

N = int(input())
lst = [*map(int, input().split())]
for i in range(N-1):
    print(lst[i] * lst[i+1], end=" ")
