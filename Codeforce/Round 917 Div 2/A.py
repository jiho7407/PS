import sys
input = sys.stdin.readline

for TC in range(int(input())):
    N = int(input())
    lst = [*map(int, input().split())]

    if 0 in lst:
        print(0)
        continue

    negcnt = 0
    for a in lst:
        if a < 0:
            negcnt += 1
    if negcnt % 2 == 1:
        print(0)
        continue
    print(1)
    print(1, 0)
