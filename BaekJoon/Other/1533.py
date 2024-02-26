import sys
input = sys.stdin.readline

mod = int(1e6)+3

N, S, E, T = map(int, input().split())
board = []
for i in range(N):
    board.append(list(input().rstrip()))
for i in range(N):
    for j in range(N):
        board[i][j] = int(board[i][j])

mat = [[0]*(5*N) for i in range(5*N)]
for i in range(N):
    for j in range(N):
        cmd = board[i][j]
        if not cmd:
            continue
        mat[i*5][j*5+cmd-1] = 1
for i in range(N):
    for j in range(4):
        mat[5*i+j+1][5*i+j] = 1


def matmul(mata, matb):
    tempmat = [[0] * (5*N) for i in range(5*N)]
    for i in range(5*N):
        for j in range(5*N):
            for k in range(5*N):
                tempmat[i][j] += mata[i][k]*matb[k][j]
                tempmat[i][j] %= mod
    return tempmat


ans = [[0] * (5*N) for i in range(5*N)]
for i in range(5*N):
    ans[i][i] = 1

while T:
    if T % 2:
        ans = matmul(ans, mat)
    mat = matmul(mat, mat)
    T //= 2

print(ans[(S-1)*5][(E-1)*5])
