import sys
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().split())
board = []
for i in range(N):
    board.append(list(input().rstrip()))
sx, sy = map(int, input().split())
gx, gy = map(int, input().split())
sx -= 1
sy -= 1
gx -= 1
gy -= 1

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
Q = deque()
Q.append((sx, sy))
while Q:
    cx, cy = Q.popleft()
    for d in range(4):
        px = cx + dx[d]
        py = cy + dy[d]
        if px < 0 or px >= N or py < 0 or py >= M:
            continue
        if px == gx and py == gy:
            if board[px][py] == 'X':
                print("YES")
                sys.exit()
            else:
                board[px][py] = 'X'
                Q.append((px, py))
            continue
        if board[px][py] == 'X':
            continue
        board[px][py] = 'X'
        Q.append((px, py))
print("NO")
