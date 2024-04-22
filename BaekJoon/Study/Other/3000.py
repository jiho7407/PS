import sys
input = sys.stdin.readline

N = int(input())
ans = 0

xlst = [[] for i in range(100001)]
ylst = [0] * 100001

for i in range(N):
    x, y = map(int, input().split())
    xlst[x].append(y)
    ylst[y] += 1

for i in range(100001):
    if len(xlst[i])<=1:
        continue
    le = len(xlst[i])
    temp = 0
    for _ in range(0, le):
        temp += ylst[xlst[i][_]]-1
    ans += temp*(le-1)


print(ans)