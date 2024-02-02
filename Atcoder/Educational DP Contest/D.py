import sys
input = sys.stdin.readline

N, W = map(int, input().split())

items = []
for i in range(N):
    items.append([*map(int, input().split())])

dp = [[0] * (W+1) for i in range(N)]

for i in range(items[0][0], W+1):
    dp[0][i] = items[0][1]

for i in range(1, N):
    w, v = items[i]
    for j in range(W+1):
        if j < w:
            dp[i][j] = dp[i-1][j]
            continue
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-w] + v)

print(dp[-1][-1])