import sys
input = sys.stdin.readline

N = int(input())
lst = []
for i in range(N):
    lst.append(tuple(map(int, input().split())))
lst.sort(key=lambda x: (x[1]/x[0]), reverse=True)

ans = 0
curtime = 0
for t, d in lst:
    ans += curtime*d
    curtime += t*2
print(ans)
