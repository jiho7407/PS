import sys
input = sys.stdin.readline

N, M = map(int, input().split())
mn = int(1e9)*(-1)
lst = []
for i in range(N):
    lst.append(int(input()))

sumlst = []
sumlst.append(0)
for i in range(N):
    sumlst.append(sumlst[-1]+lst[i])

dp = [[mn for i in range(M+1)] for j in range(N+2)]
# dp[숫자개수][구간개수]

for i in range(N+2):
    dp[i][0] = 0

for i in range(2, N+2):
    for j in range(1, M+1):
        temp = dp[i-1][j]
        for k in range(2, i+1):
            temp = max(temp, dp[k-2][j-1] + sumlst[i-1]-sumlst[k-2])
        dp[i][j] = temp

# for i in range(N+2):
#     print(dp[i])

print(dp[N+1][M])
