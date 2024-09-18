import sys
input = sys.stdin.readline

N, M, K = map(int, input().split())

board = [[0] * M for _ in range(N)]
for i in range(K):
    x, y, p = map(int, input().split())
    board[x-1][y-1] = p+1

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

for d in range(4):
    for i in range(N):
        for j in range(M):
            px = i+dx[d]
            py = j+dy[d]
            if px < 0 or px >= N or py < 0 or py >= M:
                continue
            board[i][j] = max(board[i][j], board[px][py]-1)
for d in range(4):
    for i in range(N-1, -1, -1):
        for j in range(M-1, -1, -1):
            px = i+dx[d]
            py = j+dy[d]
            if px < 0 or px >= N or py < 0 or py >= M:
                continue
            board[i][j] = max(board[i][j], board[px][py]-1)

ans = 0
for i in range(N):
    for j in range(M):
        if board[i][j]:
            ans += 1
print(ans)
