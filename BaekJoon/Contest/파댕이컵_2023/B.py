import sys
input = sys.stdin.readline

N, M = map(int, input().split())
board = []
for i in range(N*3):
    board.append(list(input().rstrip()))
for i in range(N):
    for j in range(M):
        a = int(board[3*i+1][8*j+1])
        b = int(board[3*i+1][8*j+3])
        ans = a+b
        if ans < 10 and int(board[3*i+1][8*j+5]) == ans and board[3*i+1][8*j+6] == ".":
            for k in range(1, 6):
                board[3*i][8*j+k] = "*"
                board[3*i+2][8*j+k] = "*"
            board[3*i+1][8*j] = "*"
            board[3*i+1][8*j+6] = "*"
        elif ans >= 10:
            if board[3*i+1][8*j+6] == ".":
                board[3*i][8*j+3] = "/"
                board[3*i+1][8*j+2] = "/"
                board[3*i+2][8*j+1] = "/"
                continue
            elif int(board[3*i+1][8*j+5])*10 + int(board[3*i+1][8*j+6]) == ans:
                for k in range(1, 7):
                    board[3*i][8*j+k] = "*"
                    board[3*i+2][8*j+k] = "*"
                board[3*i+1][8*j] = "*"
                board[3*i+1][8*j+7] = "*"
            else:
                board[3*i][8*j+3] = "/"
                board[3*i+1][8*j+2] = "/"
                board[3*i+2][8*j+1] = "/"
        else:
            board[3*i][8*j+3] = "/"
            board[3*i+1][8*j+2] = "/"
            board[3*i+2][8*j+1] = "/"

for i in range(N*3):
    print(''.join(board[i]))
