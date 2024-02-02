import sys
from collections import deque
input = sys.stdin.readline

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

M, N = map(int, input().split())

dist = [[-1] * M for i in range(N)]

board = []
for i in range(N):
    board.append(list(input().rstrip()))

Q = deque()
Q.append((0, 0, 0)) # x, y, 현재거리
dist[0][0] = 0

while Q:
    curx, cury, curd = Q.popleft()
    if (curx, cury) == (N-1, M-1):
        print(curd)
        break
    
    for d in range(4):
        px = curx + dx[d]
        py = cury + dy[d]
        if px < 0 or px >=N or py < 0 or py >= M:
            continue

        cmd = 0
        if board[px][py] == "1":
            cmd = 1

        if dist[px][py] != -1 and dist[px][py] <= curd + cmd:
            continue
        dist[px][py] = curd + cmd
        
        if cmd:
            Q.append((px, py, curd+1))
        else:
            Q.appendleft((px, py, curd))