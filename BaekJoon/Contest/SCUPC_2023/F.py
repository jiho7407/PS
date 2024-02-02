import sys
input = sys.stdin.readline

squares = []
for i in range(1, 320):
    squares.append(i*i)
squareset = set(squares)
for Q in range(int(input())):
    x1, y1, x2, y2, w = map(int, input().split())
    cut = w//2
    pairs = []
    for idx, i in enumerate(squares):
        # if i > cut:
        #     break
        if w-i in squareset:
            pairs.append([idx+1, squares.index(w-i)+1])
    upper = y1/x1
    lower = y2/x2
    cnt = 0
    for x, y in pairs:
        if lower <= y/x <= upper:
            cnt += 1
        # if lower <= x/y <= upper:
        #     cnt += 1
    print(cnt)
