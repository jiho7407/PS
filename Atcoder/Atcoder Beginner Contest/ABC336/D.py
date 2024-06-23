import sys
input = sys.stdin.readline

N = int(input())
lst = [*map(int, input().split())]

dp1 = [1 for i in range(N)]
dp2 = [1 for i in range(N)]
for i in range(1, N):
    if lst[i] > dp1[i-1]:
        dp1[i] = dp1[i-1]+1
    else:
        dp1[i] = min(dp1[i-1], lst[i])

for i in range(N-2, -1, -1):
    if lst[i] > dp2[i+1]:
        dp2[i] = dp2[i+1]+1
    else:
        dp2[i] = min(dp2[i+1], lst[i])

ans = 0
for i in range(N):
    ans = max(ans, min(dp1[i], dp2[i]))
print(ans)
