import sys
input = sys.stdin.readline

N = int(input())
board = []
for _ in range(N):
    board.append(input().rstrip())

rows = [0] * N
for i in range(N):
    rows[i] = board[i].count('o')

cols = [0] * N
for i in range(N):
    cols[i] = sum([board[j][i] == 'o' for j in range(N)])

ans = 0
for i in range(N):
    for j in range(N):
        if board[i][j] == 'x':
            continue
        ans += (rows[i]-1) * (cols[j]-1)

print(ans)
