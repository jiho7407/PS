import sys
from collections import deque
input = sys.stdin.readline

dirs = [[], [3, 4], [3, 4], [1, 2], [1, 2]]

N, M = map(int, input().split())


board = []
for i in range(N):
    board.append([*map(int, input().split())])

start = [*map(int, input().split())] + [0]
end = [*map(int, input().split())]
for i in range(2):
    start[i] -= 1
    end[i] -= 1
Q = deque()
Q.append(start)
visited = [[[False for i in range(5)] for j in range(M)] for k in range(N)]
visited[start[0]][start[1]][start[2]] = True

while Q:
    x, y, d, lev = Q.popleft()
    if [x, y, d] == end:
        print(lev)
        break
    for i in range(1, 4):
        px, py = x, y
        if d == 1:
            py += i
        elif d == 2:
            py -= i
        elif d == 3:
            px += i
        elif d == 4:
            px -= i
        if px < 0 or px >= N or py < 0 or py >= M:
            break
        if board[px][py] == 1:
            break
        if visited[px][py][d]:
            continue
        visited[px][py][d] = True
        Q.append([px, py, d, lev+1])
    for goald in dirs[d]:
        if visited[x][y][goald]:
            continue
        Q.append([x, y, goald, lev+1])
        visited[x][y][goald] = True
