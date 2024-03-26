import sys
input = sys.stdin.readline

for TC in range(int(input())):
    N, X = map(int, input().split())
    lst = [*map(int, input().split())]
    cnt = 0
    idx = 0
    cur = 1
    pos = True
    for idx, num in enumerate(lst):
        if cur ^ num <= X:
            cur ^= num
        elif cur > X:
            pos = False
            break
        else:
            cur = num
            cnt += 1
    if pos:
        if cur <= X:
            print(cnt+1)
        else:
            print(-1)
    else:
        print(-1)
