import sys
input = sys.stdin.readline

dx = [1, 0]
dy = [0, 1]
N, M = map(int, input().split())

board = []
for i in range(N):
    board.append(list(input().rstrip()))

dp = [[0 for i in range(M)] for j in range(N)]

if board[0][0] == "#":
    dp[0][0] = 1

for i in range(1, M):
    if board[0][i-1] == "." and board[0][i] == "#":
        dp[0][i] = dp[0][i-1] + 1
    else:
        dp[0][i] = dp[0][i-1]

for i in range(1, N):
    if board[i-1][0] == "." and board[i][0] == "#":
        dp[i][0] = dp[i-1][0] + 1
    else:
        dp[i][0] = dp[i-1][0]

for i in range(1, N):
    for j in range(1, M):

        if board[i-1][j] == "." and board[i][j] == "#":
            down = dp[i-1][j] + 1
        else:
            down = dp[i-1][j]

        if board[i][j-1] == "." and board[i][j] == "#":
            left = dp[i][j-1] + 1
        else:
            left = dp[i][j-1]

        dp[i][j] = min(down, left)

print(dp[-1][-1])
