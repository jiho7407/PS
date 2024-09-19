from collections import deque
import sys
input = sys.stdin.readline

N, M, K = map(int, input().split())

visited = [[0] * M for _ in range(N)]
lst = []
for i in range(K):
    x, y, p = map(int, input().split())
    lst.append((x-1, y-1, p))

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

lst.sort(key=lambda x: x[2], reverse=True)
Q = deque()

x, y, p = lst[0]
Q.append(lst[0])
visited[x][y] = p+1
idx = 1
while idx < K and lst[0][2] == lst[idx][2]:
    if (visited[lst[idx][0]][lst[idx][1]] < lst[idx][2]):
        visited[lst[idx][0]][lst[idx][1]] = lst[idx][2]+1
        Q.append(lst[idx])
    idx += 1
while Q:
    cx, cy, move = Q.popleft()
    for d in range(4):
        px = cx + dx[d]
        py = cy + dy[d]
        if px < 0 or px >= N or py < 0 or py >= M:
            continue
        if visited[px][py] >= move:
            continue
        visited[px][py] = move
        Q.append((px, py, move-1))
    while idx < K and move-1 == lst[idx][2]:
        if (visited[lst[idx][0]][lst[idx][1]] < lst[idx][2]):
            visited[lst[idx][0]][lst[idx][1]] = lst[idx][2]+1
            Q.append(lst[idx])
        idx += 1

ans = 0
for i in range(N):
    for j in range(M):
        if visited[i][j]:
            ans += 1
print(ans)
