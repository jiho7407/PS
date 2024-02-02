import sys
import bisect
input = sys.stdin.readline

start = []
end = []
for N in range(int(input())):
    s, e = map(int, input().split())
    start.append(s)
    end.append(e)
start.sort()
end.sort()

ans = 0
for idx, s in enumerate(start):
    ans = max(ans, idx+1 - bisect.bisect_right(end, s))
print(ans)
