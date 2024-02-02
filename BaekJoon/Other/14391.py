import sys
input = sys.stdin.readline

N, M = map(int, input().split())
board = []
for i in range(N):
    board.append(list(input().rstrip()))


def calc(a):
    calcans = 0
    for i in range(N):  # 가로 = 비트마스킹 1 먼저 계산
        temp = 0
        for j in range(M):
            cmd = a & (1 << i*M+j)
            if cmd:
                temp = temp*10 + int(board[i][j])
            else:
                calcans += temp
                temp = 0
        calcans += temp

    for j in range(M):  # 세로 = 비트마스킹 0
        temp = 0
        for i in range(N):
            cmd = a & (1 << i*M+j)
            if cmd == 0:
                temp = temp*10 + int(board[i][j])
            else:
                calcans += temp
                temp = 0
        calcans += temp
    return calcans


ans = 0
for i in range(1 << (N*M)):
    ans = max(ans, calc(i))
print(ans)
