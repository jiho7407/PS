dx = [-1, -1, -1, 0, 1, 1, 1, 0]
dy = [-1, 0, 1, 1, 1, 0, -1, -1]

N = int(input())
board = [[-1] * 19 for _ in range(19)]


def cnt(r, c, dir, stone):
    px, py = r, c
    cnt = 0
    while True:
        px += dx[dir]
        py += dy[dir]
        if px < 0 or px >= 19 or py < 0 or py >= 19:
            return cnt
        if board[px][py] != stone:
            return cnt
        cnt += 1


def check(r, c, stone):
    for i in range(4):
        if cnt(r, c, i, stone) + cnt(r, c, i+4, stone) == 4:
            return True
    return False


ans = -1
for i in range(N):
    r, c = map(int, input().split())
    if ans >= 0:
        continue
    r -= 1
    c -= 1
    if i % 2:
        board[r][c] = 0
        if check(r, c, 0):
            ans = i+1
    else:
        board[r][c] = 1
        if check(r, c, 1):
            ans = i+1
print(ans)
