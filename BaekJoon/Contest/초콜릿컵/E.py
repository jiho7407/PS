import sys
from collections import deque
input = sys.stdin.readline

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

N = int(input())
board = []
for i in range(N):
    board.append(list(input().rstrip()))

def solve():
    visited = [[-1] * N for i in range(N)]
    cnt = 0
    con = True
    for i in range(N):
        for j in range(N):
            if board[i][j] == ".":
                continue
            if visited[i][j] != -1:
                continue
            Q = deque()
            Q.append((i, j, 1))
            visited[i][j] = 1
            cnt += 1
            while Q:
                curx, cury, lev = Q.popleft()
                for d in range(4):
                    px = curx + dx[d]
                    py = cury + dy[d]
                    if px<0 or px>=N or py< 0 or py>=N:
                        continue
                    if board[px][py] == ".":
                        continue
                    if visited[px][py] >= lev:
                        con = False
                        break
                    if visited[px][py] != -1:
                        continue
                    Q.append((px, py, lev+1))
                    visited[px][py] = lev+1
    if cnt > 1:
        con = False
    return con

ans = []
for i in range(N):
    for j in range(N):
        if board[i][j] == ".":
            continue
        board[i][j] = "."
        if solve():
            ans.append((i+1, j+1))
        board[i][j] = "#"

print(len(ans))
for i, j in ans:
    print(i, j) 