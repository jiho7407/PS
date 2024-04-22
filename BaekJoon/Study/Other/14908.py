import sys
input = sys.stdin.readline

N = int(input())
lst = []
for i in range(N):
    t, s = map(int, input().split())
    lst.append((i+1, s, t))

lst.sort(key = lambda x: (x[2]/x[1]))

for idx, s, t in lst:
    print(idx, end=" ")