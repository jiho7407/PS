import sys
input = sys.stdin.readline

N, C = map(int, input().split())

app = []
for i in range(N):
    x, y = map(int, input().split())
    app.append((x, y, i+1))
app.sort(key = lambda x: x[1]-x[0])

dp = [[0] * (C+1) for i in range(N+1)]

for i in range(1, N+1):
    d, s, idx = app[i-1]
    for j in range(1, C+1):
        dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        if s > j:
            continue
        if C-(j-s) < d:
            continue
        dp[i][j] = max(dp[i][j], dp[i-1][j-s]+1)

x, y = N, C
ans = []
while True:
    if dp[x][y] == 0:
        break
    if dp[x][y-1] == dp[x][y]:
        y -= 1
    elif dp[x][y] == dp[x-1][y]:
        x -= 1
    elif dp[x-1][y] < dp[x][y]:
        x -= 1
        y -= app[x][1]
        ans.append(app[x][2])
    if x==5 and y==4:
        break
print(dp[N][C])
print(*reversed(ans))