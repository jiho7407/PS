import sys
input = sys.stdin.readline

for TC in range(int(input())):
    N = int(input())
    board = [list(map(int, input().split())) for i in range(2)]
    a, b, c, d = map(int, input().split())
    a -= 1
    b -= 1
    c -= 1
    d -= 1
    if c < a:
        a, c = c, a
        b, d = d, b
    dp = [0] * N

    left = 0
    cursum = 0
    for i in range(a-1, -1, -1):
        left = max(left, cursum + max(board[0][i], board[1][i], board[0][i]+board[1][i]))
        cursum += board[0][i] + board[1][i]

    right = 0
    cursum = 0
    for i in range(c+1, N):
        right = max(right, cursum + max(board[0][i], board[1][i], board[0][i]+board[1][i]))
        cursum += board[0][i] + board[1][i]

    if a == c:
        print(board[0][a] + board[1][a] + max(left, right))
        continue

    dp[a] = max(board[b][a], board[0][a] + board[1][a], left + board[0][a] + board[1][a])
    for i in range(a+1, c+1):
        dp[i] = dp[i-1] + max(board[0][i], board[1][i], board[0][i] + board[1][i])

    print(dp[c-1]+max(board[d][c], board[0][c]+board[1][c]+right))