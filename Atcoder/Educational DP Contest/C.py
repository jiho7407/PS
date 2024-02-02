N = int(input())

lst = []
for i in range(N):
    lst.append([*map(int, input().split())])

dp = [[0] * 3 for i in range(N)]

dp[0] = lst[0]

for i in range(1, N):
    dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + lst[i][0]
    dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + lst[i][1]
    dp[i][2] = max(dp[i-1][1], dp[i-1][0]) + lst[i][2]

print(max(dp[N-1]))