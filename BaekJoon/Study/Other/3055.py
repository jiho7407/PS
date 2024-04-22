import sys
from collections import deque
input = sys.stdin.readline

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
N, M = map(int, input().split())
board = []
for i in range(N):
    board.append(list(input().rstrip()))

Sboard = [[-1 for i in range(M)] for j in range(N)]
Wboard = [[-1 for i in range(M)] for j in range(N)]


SQ = deque()
WQ = deque()
for i in range(N):
    for j in range(M):
        if board[i][j] == 'S':
            SQ.append((i, j, 1))
            Sboard[i][j] = 0
        elif board[i][j] == '*':
            WQ.append((i, j, 1))
            Wboard[i][j] = 0
        elif board[i][j] == 'D':
            Dlocate = [i, j]

while True:
    if not WQ and not SQ:
        break
    tempWQ = deque()
    for x, y, lev in WQ:
        for d in range(4):
            px = x + dx[d]
            py = y + dy[d]
            if px < 0 or px >= N or py < 0 or py >= M:
                continue
            if board[px][py] in ["X", "D"]:
                continue
            if Wboard[px][py] != -1:
                continue
            Wboard[px][py] = lev
            tempWQ.append((px, py, lev+1))
    WQ = tempWQ

    tempSQ = deque()
    for x, y, lev in SQ:
        for d in range(4):
            px = x + dx[d]
            py = y + dy[d]
            if px < 0 or px >= N or py < 0 or py >= M:
                continue
            if board[px][py] == "X":
                continue
            if Wboard[px][py] != -1 and Wboard[px][py] <= lev:
                continue
            if Sboard[px][py] != -1:
                continue
            Sboard[px][py] = lev
            tempSQ.append((px, py, lev+1))
    SQ = tempSQ

ans = Sboard[Dlocate[0]][Dlocate[1]]

if ans == -1:
    print("KAKTUS")
else:
    print(ans)
