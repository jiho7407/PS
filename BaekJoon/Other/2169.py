import sys
input = sys.stdin.readline

N, M = map(int, input().split())
board = []
for i in range(N):
    board.append([*map(int, input().split())])

ansboard = [[0 for j in range(M)] for i in range(N)]
ansboard[0][0] = board[0][0]
for i in range(1, M):
    ansboard[0][i] = ansboard[0][i-1] + board[0][i]

for i in range(1, N):
    LRlst = [0 for i in range(M)]
    RLlst = [0 for i in range(M)]
    LRlst[0] = ansboard[i-1][0] + board[i][0]
    RLlst[M-1] = ansboard[i-1][M-1] + board[i][M-1]
    for j in range(1, M):
        LRlst[j] = max(LRlst[j-1], ansboard[i-1][j]) + board[i][j]
        RLlst[M-j-1] = max(RLlst[M-j], ansboard[i-1][M-j-1]) + board[i][M-j-1]
    for j in range(M):
        ansboard[i][j] = max(LRlst[j], RLlst[j])

print(ansboard[N-1][M-1])
