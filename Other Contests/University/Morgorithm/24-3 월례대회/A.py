board = []
for i in range(8):
    board.append(input())

score = {".": 0, "K": 0, "k": 0, "P": 1, "p": -1, "N": 3,
         "n": -3, "B": 3, "b": -3, "R": 5, "r": -5, "Q": 9, "q": -9}

ans = 0
for i in range(8):
    for j in range(8):
        ans += score.get(board[i][j])
print(ans)
