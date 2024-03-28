import sys
input = sys.stdin.readline

for TC in range(int(input())):
    a, b, c = map(int, input().split())
    if a+b+c != 2*a+b + 1:
        print(-1)
        continue
    lev = -1
    curnode = 1
    while (True):
        if curnode == 0:
            break
        temp = 0
        amx = min(a, curnode)
        temp += 2*amx
        a -= amx
        curnode -= amx

        bmx = min(b, curnode)
        temp += bmx
        b -= bmx
        curnode -= bmx

        lev += 1
        curnode = temp
    print(lev)
