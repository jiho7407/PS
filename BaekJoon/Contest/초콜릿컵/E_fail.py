import sys
from collections import deque
input = sys.stdin.readline

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

N = int(input())
board = []
for i in range(N):
    board.append(list(input().rstrip()))

chocnt = 0
for i in range(N):
    for j in range(N):
        if board[i][j] == "#":
            chocnt += 1
ans = []
    
def solve():
    global choc
    choc = 0
    check = 0
    visited = [[False] * N for i in range(N)]
    result = False
    for i in range(N):
        for j in range(N):
            if board[i][j] == ".":
                continue
            if visited[i][j]:
                continue
            check += 1
            Q = deque()
            Q.append((i, j))
            while Q:
                cnt = 0
                curx, cury = Q.popleft()
                for d in range(4):
                    px = curx + dx[d]
                    py = cury + dy[d]
                    if px<0 or px>=N or py<0 or py>=N:
                        continue
                    if visited[px][py]:
                        continue
                    if board[px][py] == "#":
                        choc += 1
                        Q.append((px, py))
                        visited[px][py] = True
                if cnt > 2:
                    if curx != i or cury != j:
                        return False
    if check > 1:
        return False
    if choc != chocnt - 1:
        return False
    return True

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