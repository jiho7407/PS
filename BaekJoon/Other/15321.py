import sys
input = sys.stdin.readline

N = int(input())
lst = [int(input()) for i in range(N)]

dp = [[0] * N for i in range(N)]
mx = [[0] * N for i in range(N)]

for i in range(N):
    tempmx = lst[i]
    for j in range(i, N):
        tempmx = max(tempmx, lst[j])
        mx[i][j] = tempmx

for i in range(N-1):
    dp[i][i+1] = abs(lst[i] - lst[i+1])

for i in range(N-2, -1, -1):
    for j in range(i+2, N):
        temp = int(1e10)
        for k in range(i, j):
            temp = min(temp, dp[i][k] + dp[k+1][j] +
                       abs(mx[i][k] - mx[k+1][j]))
        dp[i][j] = temp

print(dp[0][N-1])
