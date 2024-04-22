import sys
input = sys.stdin.readline

board = ''

for i in range(10):
    cmd = list(input().rstrip())
    for j in range(10):
        if cmd[j] == "#":
            board += "0"
        else:
            board += "1"

board = int(board, 2)
answered = False
ans = 1000


def press(curboard, button):
    tempset = set()

    tempset.add(button)

    if button // 10 != 0:
        tempset.add(button-10)

    if button // 10 != 9:
        tempset.add(button+10)

    if button % 10 != 0:
        tempset.add(button-1)

    if button % 10 != 9:
        tempset.add(button+1)

    for x in tempset:
        curboard ^= (1 << x)
    return curboard


for i in range(1 << 10):
    cnt = 0
    tempboard = board
    for j in range(10):
        if i & (1 << j):
            tempboard = press(tempboard, j)
            cnt += 1

    for j in range(1, 10):
        for k in range(10):
            locate = 10*j + k
            if tempboard & (1 << (locate-10)):  # 한줄 아래가 켜져있으면
                tempboard = press(tempboard, locate)
                cnt += 1
    if tempboard == 0:
        ans = min(ans, cnt)

if ans == 1000:
    print(-1)
else:
    print(ans)
