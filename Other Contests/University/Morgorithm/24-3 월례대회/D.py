import sys

board = [[0]*7 for i in range(6)]
cnt = [0] * 7

dx = [-1, -1, -1, 0, 0, 1, 1, 1]
dy = [-1, 0, 1, -1, 1, -1, 0, 1]

lst = []


def checkall(p):
    for i in range(6):
        for j in range(7):
            if check(i, j, p):
                return True
    return False


def check(x, y, p):
    for d in range(8):
        cx, cy = dx[d], dy[d]
        cnt = 0
        for i in range(4):
            px = x + cx*i
            py = y + cy*i
            if px < 0 or px >= 6 or py < 0 or py >= 7:
                continue
            if board[px][py] == p:
                cnt += 1
        if cnt == 4:
            return True
    return False


for i in range(21):
    a, b = map(int, input().split())
    lst.append((a-1, b-1))

for i in range(21):
    a, b = lst[i]
    board[cnt[a]][a] = 1
    if checkall(1):
        print("sk", i+1)
        sys.exit()
    cnt[a] += 1

    board[cnt[b]][b] = 2
    if checkall(2):
        print("ji", i+1)
        sys.exit()
    cnt[b] += 1

print("ss")
