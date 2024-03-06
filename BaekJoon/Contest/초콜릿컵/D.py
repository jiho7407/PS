import sys
input = sys.stdin.readline

N = int(input())
visited = [[False] * N for i in range(N)]
board = []
for i in range(N):
    board.append(input().rstrip())

suc = True
for i in range(N):
    for j in range(i+1):
        if visited[i][j]:
            continue
        if i+1>=N:
            suc = False
            break
        if board[i][j] == "R":
            if board[i+1][j] == "B" or board[i+1][j+1] == "B":
                suc = False
                break
            if visited[i+1][j] or visited[i+1][j+1] :
                suc = False
                break
            visited[i][j] = True
            visited[i+1][j] = True
            visited[i+1][j+1] = True
        else:
            if i == j:
                suc = False
                break
            if board[i][j+1] == "R" or board[i+1][j+1] == "R":
                suc = False
                break
            if visited[i][j+1] or visited[i+1][j+1] :
                suc = False
                break
            visited[i][j] = True
            visited[i][j+1] = True
            visited[i+1][j+1] = True


if suc:
    print(1)
else:
    print(0)