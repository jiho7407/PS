import sys
input = sys.stdin.readline

N, W = map(int, input().split())

items = []
for i in range(N):
    items.append([*map(int, input().split())])

V = int(1e5)
dp = [[int(1e10)] * (V+1) for i in range(N)]

for i in range(items[0][1]+1):
    dp[0][i] = items[0][0]

for i in range(1, N):
    w, v = items[i]
    for j in range(V+1):
        if j < v:
            dp[i][j] = min(dp[i-1][j], w)
            continue
        if j == v:
            dp[i][j] = min(dp[i-1][j], dp[i-1][j-v] + w, w)
            continue
        dp[i][j] = min(dp[i-1][j], dp[i-1][j-v] + w)

ans = 0
for i in range(V+1):
    cmd = dp[-1][i]
    if cmd > W:
        continue
    ans = max(ans, i)

print(ans)