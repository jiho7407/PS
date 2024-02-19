import sys
input = sys.stdin.readline

N = int(input())
lst = [int(input()) for i in range(N)]

dp = [[int(1e10)] * N for i in range(N)]

for i in range(N-1):
    dp[i][i+1] = abs(lst[i]-lst[i+1])

for i in range(N):
    print(dp[i])

for i in range(N-2, -1, -1):
    for j in range(i+1, N):
        print(i, j)
        dp[i][j] = min(dp[i][j], dp[i+1][j], dp[i][j-1])

for i in range(N):
    print(dp[i])