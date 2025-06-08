import sys
input = sys.stdin.readline

p = [7, 17]

for TC in range(int(input())):
    N, M = map(int, input().split())
    lst = [*map(int, input().split())]
    seven = 0
    seventeen = 0
    other = 0
    out = False
    a = 2023
    for i in range(N):
        cmd = lst[i]
        if (a/cmd).is_integer():
            a //= cmd
        else:
            out = True
    if out:
        print("NO")
        continue
    stk = [a]
    for i in range(M-1):
        stk.append(1)
    print("YES")
    print(*stk)
