import sys

input = sys.stdin.readline

N, M, Q = map(int, input().split())
board = []
for i in range(N):
    board.append([*map(int, input().split())])

pfsum = [[0] * M for i in range(N)]
for i in range(M):
    pfsum[0][i] = board[0][i]

for i in range(1, N):
    pfsum[i][0] = pfsum[i - 1][0] + board[i][0]

for j in range(1, M):
    vsum = pfsum[0][j]
    for i in range(1, N):
        vsum += board[i][j]
        pfsum[i][j] = pfsum[i - 1][j - 1] + vsum

for i in range(Q):
    r, c = map(int, input().split())
    print(pfsum[r - 1][c - 1])
