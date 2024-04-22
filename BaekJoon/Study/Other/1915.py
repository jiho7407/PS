import sys
input = sys.stdin.readline

N, M = map(int, input().split())
board = []
for i in range(N):
    board.append(input().rstrip())

dp = [[] for i in range(N)]
dp[0] = list(board[0])
for i in range(M):
    dp[0][i] = int(dp[0][i])


for i in range(1, N):
    dp[i].append(int(board[i][0]))


for i in range(1, N):
    for j in range(1, M):
        if board[i][j] == '1':
            dp[i].append(min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j])+1)
        else:
            dp[i].append(0)

ans = 0
for i in range(N):
    ans = max(ans, max(dp[i]))
print(ans**2)
