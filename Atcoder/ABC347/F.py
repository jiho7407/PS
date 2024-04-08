import sys
input = sys.stdin.readline

N, M = map(int, input().split())
board = []
for i in range(N):
    board.append(list(map(int, input().split())))
pfsum = [[0 for _ in range(N+1)] for _ in range(N+1)]
for i in range(N):
    for j in range(N):
        pfsum[i+1][j+1] = pfsum[i][j+1] + \
            pfsum[i+1][j] - pfsum[i][j] + board[i][j]

grid = []
for i in range(N-M+1):
    grid.append([])
    for j in range(N-M+1):
        grid[i].append(pfsum[i+M][j+M] - pfsum[i][j+M] -
                       pfsum[i+M][j] + pfsum[i][j])

lst = []
for i in range(N-M+1):
    for j in range(N-M+1):
        lst.append((grid[i][j], i, j))
lst.sort(reverse=True)
dp = [[-1 for _ in range(4)] for _ in range(len(lst)+1)]
dp[0] = 0

for i in range(1, len(lst)+1):
    x, y, z = lst[i]
    for j in range(3, 0, -1):
        if dp[y][j-1] == -1:
            continue
        dp[y+M][j] = max(dp[y+M][j], dp[y][j] + x)
