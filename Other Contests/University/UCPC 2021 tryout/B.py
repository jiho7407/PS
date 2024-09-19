import sys
from collections import deque
input = sys.stdin.readline

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

N, M = map(int, input().split())
board = []
for i in range(N):
    board.append([*map(int, input().split())])

groups = []
groupnum = []

visited = [[False for i in range(M)] for j in range(N)]

for i in range(N):
    for j in range(M):
        if visited[i][j]:
            continue
        groupnum.append(board[i][j])
        templst = []
        templst.append((i, j))
        q = deque()
        q.append((i, j))
        visited[i][j] = True
        while q:
            curx, cury = q.popleft()
            for d in range(4):
                px = curx+dx[d]
                py = cury+dy[d]
                if px<0 or px>=N or py<0 or py>=M:
                    continue
                if visited[px][py]:
                    continue
                if board[px][py] != groupnum[-1]:
                    continue
                templst.append((px, py))
                q.append((px, py))
                visited[px][py] = True
        groups.append(templst)

compare = []
for i in range(N):
    compare.append([*map(int, input().split())])

pos = True
changed = False

for i in range(len(groupnum)):
    num = groupnum[i]
    group = groups[i]

    curnum = compare[group[0][0]][group[0][1]]
    if num != curnum:
        if changed:
            pos = False
            break
        changed = True

    for x, y in group:
        if compare[x][y] != curnum:
            pos = False
            break

if pos:
    print("YES")
else:
    print("NO")