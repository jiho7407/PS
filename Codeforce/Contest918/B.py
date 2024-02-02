import sys
input = sys.stdin.readline

for TC in range(int(input())):
    board = []
    for i in range(3):
        board.append(input().rstrip())
    a = 0
    b = 0
    c = 0
    for i in range(3):
        for j in range(3):
            if board[i][j] == "A":
                a += 1

            if board[i][j] == "B":
                b += 1

            if board[i][j] == "C":
                c += 1
    if a != 3:
        print("A")

    if b != 3:
        print("B")

    if c != 3:
        print("C")
