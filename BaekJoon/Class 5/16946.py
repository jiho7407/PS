from collections import deque
import sys
input = sys.stdin.readline
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
n, m = map(int, input().split())
board = []
for i in range(n):
    board.append(list(input().rstrip()))
visited = [[False for j in range(m)]for i in range(n)]
newmap = [[0 for j in range(m)]for i in range(n)]

Q = deque()
for i in range(n):
    for j in range(m):
        if visited[i][j] or board[i][j] == '1':
            continue
        area = 0
        Q.append([i,j])
        visited[i][j] = True
        wallst = []
        while Q:
            curx, cury = Q.popleft()
            area += 1
            for d in range(4):
                px = curx + dx[d]
                py = cury + dy[d]
                if(px<0 or px>=n or py<0 or py>=m):
                    continue
                if not visited[px][py]:
                    visited[px][py] = True
                    if board[px][py] == '0':
                        Q.append([px, py])
                    else:
                        wallst.append([px, py])
        for x, y in wallst:
            newmap[x][y] += area
            visited[x][y] = False

for i in range(n):
    for j in range(m):
        if board[i][j] == '1':
            newmap[i][j] = (newmap[i][j]+1)%10

for i in range(n):
    for j in range(m):
        print(newmap[i][j], end='')
    print()