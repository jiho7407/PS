import sys
import bisect
input = sys.stdin.readline

N = int(input())
board = []
rows = [[] for i in range(N)]
cols = [[] for i in range(N)]
for i in range(N):
    board.append([*map(int, input().split())])
for i in range(N):
    for j in range(N):
        rows[i].append(board[i][j])
        cols[i].append(board[j][i])
for i in range(N):
    rows[i].sort()
    cols[i].sort()

ans = 0
for i in range(N):
    for j in range(N):
        cmd = board[i][j]
        r = bisect.bisect_left(rows[i], cmd)
        c = bisect.bisect_left(cols[j], cmd)
        ans += r*(N-c-1) + c*(N-r-1)

print(ans//2)