board = []
for i in range(5):
    board.append([*map(int, input().split())])
r, c = map(int, input().split())

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
visited = [[False for i in range(5)] for j in range(5)]

INF = 123456789


def btr(x, y, lev, cnt):
    if cnt == 3:
        return lev
    temp = INF
    for d in range(4):
        px = x + dx[d]
        py = y + dy[d]
        if px < 0 or px >= 5 or py < 0 or py >= 5:
            continue
        if board[px][py] == -1:
            continue
        if visited[px][py]:
            continue

        visited[px][py] = True
        if board[px][py] == 1:
            temp = min(temp, btr(px, py, lev+1, cnt+1))
        else:
            temp = min(temp, btr(px, py, lev+1, cnt))
        visited[px][py] = False
    return temp


visited[r][c] = True
ans = btr(r, c, 0, 0)
if ans == INF:
    print(-1)
else:
    print(ans)
