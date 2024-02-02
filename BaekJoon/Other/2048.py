import sys

input = sys.stdin.readline

lst = [[0, 2, 2, 5], [0, 1, 3, 3], [0, 0, 2, 4], [0, 0, 0, 3]]
for TC in range(int(input())):
    l, r = map(int, input().split())
    if r < 4:
        print(lst[l][r])
    else:
        print(r)
