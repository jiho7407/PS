import sys
input = sys.stdin.readline

N, K = map(int, input().split())
lst = [*map(int, input().split())]

cur = 0
ans = 0
for a in lst:
    if cur+a > K:
        ans += 1
        cur = a
    else:
        cur += a
ans += 1
print(ans)
