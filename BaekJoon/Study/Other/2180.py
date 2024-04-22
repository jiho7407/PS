import sys
input = sys.stdin.readline

N = int(input())
lst = [list(map(int, input().split())) for i in range(N)]
mn = 0.000001
for i in range(N):
    if lst[i][0] == 0:
        lst[i][0] = mn

lst.sort(key = lambda x: (x[1]/x[0], x[0]))

ans = 0
t = 0
for a, b in lst:
    if a == mn:
        a = 0
    ans += a*t+b
    t += a*t+b
    ans %= 40000
    t %= 40000

print(ans)