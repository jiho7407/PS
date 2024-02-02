import sys
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().split())
board = []
for i in range(N):
    board.append(list(input().rstrip()))

visited = [[False for i in range(M)]for j in range(N)]
Q = deque()

ans = 0


def printer():
    for i in range(N):
        print(visited[i])


for i in range(N):
    for j in range(M):
        if visited[i][j]:
            continue
        Q.append((i, j))
        visitset = set()
        visitset.add((i, j))
        while Q:
            px, py = Q.popleft()
            cmd = board[px][py]
            if cmd == 'U':
                px -= 1
            elif cmd == "D":
                px += 1
            elif cmd == "L":
                py -= 1
            elif cmd == "R":
                py += 1
            if px < 0 or px >= N or py < 0 or py >= M:
                continue
            if visited[px][py]:
                continue
            if (px, py) in visitset:
                ans += 1
                continue
            visitset.add((px, py))
            Q.append((px, py))
        for x, y in visitset:
            visited[x][y] = True
print(ans)
