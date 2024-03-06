N = int(input())

board2 = [["R"],
          ["R", "R"]]
board9 = [["R"],
          ["R", "R"],
          ["R", "B", "B"],
          ["R", "R", "B", "R"],
          ["R", "B", "B", "R", "R"],
          ["R", "R", "B", "B", "B", "R"],
          ["B", "B", "B", "B", "B", "R", "R"],
          ["R", "B", "R", "B", "R", "B", "B", "R"],
          ["R", "R", "R", "R", "R", "R", "B", "R", "R"]]
board11 = [["R"],
          ["R", "R"],
          ["R", "B", "B"],
          ["R", "R", "B", "R"],
          ["R", "B", "B", "R", "R"],
          ["R", "R", "B", "B", "B", "R"],
          ["B", "B", "B", "B", "B", "R", "R"],
          ["R", "B", "R", "B", "R", "B", "B", "R"],
          ["R", "R", "R", "R", "R", "R", "B", "R", "R"],
          ["R", "B", "B", "R", "B", "B", "R", "B", "B", "R"],
          ["R", "R", "B", "R", "R", "B", "R", "R", "B", "R", "R"]]

board12 = [["R"],
          ["R", "R"],
          ["R", "B", "B"],
          ["R", "R", "B", "R"],
          ["R", "B", "B", "R", "R"],
          ["R", "R", "B", "B", "B", "R"],
          ["B", "B", "B", "B", "B", "R", "R"],
          ["R", "B", "R", "B", "R", "B", "B", "R"],
          ["R", "R", "R", "R", "R", "R", "B", "R", "R"],
          ["B", "B", "B", "B", "B", "B", "B", "B", "B", "B"],
          ["R", "B", "R", "B", "R", "B", "R", "B", "R", "B", "R"],
          ["R", "R", "R", "R", "R", "R", "R", "R", "R", "R", "R", "R"]]

block2 = [["R", "B", "B", "R", "B", "B", "R", "B", "B", "R", "B", "B"],
          ["R", "R", "B", "R", "R", "B", "R", "R", "B", "R", "R", "B"]]

block3 = [["B", "B", "B", "B", "B", "B", "B", "B", "B", "B", "B", "B"],
          ["R", "B", "R", "B", "R", "B", "R", "B", "R", "B", "R", "B"],
          ["R", "R", "R", "R", "R", "R", "R", "R", "R", "R", "R", "R"]]

ans = [[] for i in range(N)]
idx = 0
while N-idx >= 12:
    for j in range(idx//12):
        for i in range(12):
            ans[idx+i].extend(block3[i%3])
    for i in range(12):
        ans[idx+i].extend(board12[i])
    idx += 12

if N-idx == 2:
    for j in range(idx//12):
        for i in range(2):
            ans[idx+i].extend(block2[i])
    for i in range(2):
        ans[idx+i].extend(board2[i])

if N-idx == 9:
    for j in range(idx//12):
        for i in range(9):
            ans[idx+i].extend(block3[i%3])
    for i in range(9):
        ans[idx+i].extend(board9[i])

if N-idx == 11:
    for j in range(idx//12):
        for i in range(9):
            ans[idx+i].extend(block3[i%3])
        for i in range(2):
            ans[idx+9+i].extend(block2[i%2])
    for i in range(11):
        ans[idx+i].extend(board11[i])

for i in range(N):
    print("".join(ans[i]))

