import sys
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().split())
board = []
for i in range(N):
    board.append(input().rstrip())

visited = [[0 for i in range(M)]for j in range(N)]

ans = 0
for i in range(N):
    for j in range(M):
        if visited[i][j]:
            continue
        Q = deque()
        path = set()
        Q.append((i, j))
        path.add((i, j))
        while Q:
            cx, cy = Q.popleft()
            cmd = board[cx][cy]
            if cmd == "U":
                cx -= 1
            elif cmd == "D":
                cx += 1
            elif cmd == "L":
                cy -= 1
            elif cmd == "R":
                cy += 1
            if cx < 0 or cx >= N or cy < 0 or cy >= M or visited[cx][cy] == 2:
                for px, py in path:
                    visited[px][py] = 2
                    ans += 1
                break
            if (cx, cy) in path or visited[cx][cy] == 1:
                for px, py in path:
                    visited[px][py] = 1
                break
            path.add((cx, cy))
            Q.append((cx, cy))
print(ans)
