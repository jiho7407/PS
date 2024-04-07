import sys
input = sys.stdin.readline
sys.setrecursionlimit(int(1e5))

N, M = map(int, input().split())
board = []
for i in range(N):
    board.append(list(input().rstrip()))
    for j in range(M):
        if board[i][j] == "S":
            start = (i, j)
        elif board[i][j] == "T":
            goal = (i, j)
medicine = [[0] * M for _ in range(N)]
for medi in range(int(input())):
    r, c, e = map(int, input().split())
    medicine[r - 1][c - 1] = e

dx = [-1, 1,  0, 0]
dy = [0, 0, -1, 1]
dp = [[-1] * M for _ in range(N)]


def dfs(cx, cy, energy):
    if energy <= 0:
        return False
    for d in range(4):
        px = cx + dx[d]
        py = cy + dy[d]
        if px < 0 or px >= N or py < 0 or py >= M:
            continue
        if board[px][py] == "#":
            continue
        if (px, py) == goal:
            return True
        next_energy = max(energy - 1, medicine[px][py])
        if dp[px][py] >= next_energy:
            continue
        dp[px][py] = next_energy
        if dfs(px, py, next_energy):
            return True
    return False


dp[start[0]][start[1]] = medicine[start[0]][start[1]]
if dfs(start[0], start[1], medicine[start[0]][start[1]]):
    print("Yes")
else:
    print("No")
