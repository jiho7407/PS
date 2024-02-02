import sys
input = sys.stdin.readline

mod = int(1e9)+7

H, W, N = map(int, input().split())

walls = set()
for i in range(N):
    r, c = map(int, input().split())
    walls.add((r, c))
dp = [[0] * (W+1) for i in range(H+1)]

dp[1][0] = 1
for i in range(H):
    for j in range(W):
        if (i+1, j+1) in walls:
            continue
        dp[i+1][j+1] = (dp[i+1][j] + dp[i][j+1])%mod

print(dp[-1][-1])