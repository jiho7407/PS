board = []
for i in range(9):
    board.append(list(input()))
for i in range(9):
    for j in range(9):
        board[i][j] = int(board[i][j])

finded = False


def bfs(a):
    global finded
    if finded:
        return
    if a == 81:
        finded = True
        for t in range(9):
            for k in range(9):
                print(board[t][k], end="")
            print()
        return
    x, y = a // 9, a % 9
    if board[x][y] != 0:
        bfs(a + 1)
        return
    for i in range(1, 10):
        possible = True
        for j in range(9):
            if board[x][j] == i:
                possible = False
                break
            if board[j][y] == i:
                possible = False
                break
        xblock = x // 3
        yblock = y // 3
        for r in range(3):
            for c in range(3):
                if board[xblock * 3 + r][yblock * 3 + c] == i:
                    possible = False
                    break
        if possible:
            board[x][y] = i
            bfs(a + 1)
            board[x][y] = 0


for i in range(64):
    if board[i // 9][i % 9] == 0:
        bfs(i)
        break
