N = int(input())
coins = [*map(float, input().split())]

dp = [[0] * (N+1) for i in range(N)]

dp[0][0] = 1 - coins[0]
dp[0][1] = coins[0]

for i in range(1, N):
    p = coins[i]
    dp[i][0] = dp[i-1][0] * (1 - p)
    for j in range(1, i+2):
        dp[i][j] = dp[i-1][j]*(1-p) + dp[i-1][j-1]*p

print(sum(dp[N-1][(N+1)//2:]))