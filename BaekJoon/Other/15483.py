import sys
input = sys.stdin.readline

B = input().rstrip()
A = input().rstrip()

N = len(A)
M = len(B)

dp = [[0 for i in range(M+1)] for j in range(N+1)]

for i in range(1, N+1):
    dp[i][0] = dp[i-1][0]+1
for j in range(1, M+1):
    dp[0][j] = dp[0][j-1] + 1

for i in range(1, N+1):
    for j in range(1, M+1):
        if A[i-1] == B[j-1]:
            dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]+1, dp[i][j-1]+1)
        else:
            dp[i][j] = min(dp[i-1][j-1] + 1, dp[i-1][j]+1, dp[i][j-1]+1)

print(dp[N][M])
