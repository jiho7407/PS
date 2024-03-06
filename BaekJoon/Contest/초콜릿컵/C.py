import sys
input = sys.stdin.readline

for tc in range(int(input())):
    Y, X, a, b = map(int, input().split())
    ans = 0
    curx, cury = 0, 0
    while curx<X and cury<Y:
        ans += min(b, X - curx) * (Y - cury)
        ans += min(a, Y - cury) * (X - curx)
        ans -= min(b, X - curx) * min(a, Y - cury)
        curx += b*2
        cury += a*2
    print(ans)