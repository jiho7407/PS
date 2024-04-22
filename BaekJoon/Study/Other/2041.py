N, M = map(int, input().split())

board = [[0] * M for i in range(N)]

board[0][0] = 1
dist = 2*N*M-N-M

for i in range(N):
    for j in range(M-1):
        if (i+j)%2:
            board[i][j+1] = board[i][j] - dist
        else:
            board[i][j+1] = board[i][j] + dist
        dist -= 1
    if i == N-1:
        break
    if i%2:
        board[i+1][0] = board[i][0] - dist
    else:
        board[i+1][0] = board[i][0] + dist
    dist -= M

for i in range(N):
    print(*board[i])