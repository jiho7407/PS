import sys
import bisect
input = sys.stdin.readline

N, H = map(int, input().split())
floor = []
top = []
for i in range(N):
    cmd = int(input())
    if i % 2:
        top.append(H - cmd)
    else:
        floor.append(cmd)
floor.sort()
top.sort()
ans = 0
minans = 1e6
for i in range(H):
    floorcnt = N//2 - bisect.bisect_right(floor, i)
    topcnt = bisect.bisect_right(top, i)
    cnt = floorcnt + topcnt
    if minans > cnt:
        minans = cnt
        ans = 1
    elif minans == cnt:
        ans += 1
print(minans, ans)
