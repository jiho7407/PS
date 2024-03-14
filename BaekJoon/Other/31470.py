import sys
import math
input = sys.stdin.readline

for TC in range(int(input())):
    X, Y, x, y = map(int, input().split())
    ans = 0

    rx, ry = X % x, Y % y

    w1 = math.ceil(X/x)
    w2 = math.ceil((X-rx)/x)

    h1 = math.ceil(Y/y)
    h2 = math.ceil((Y-ry)/y)

    x1 = math.ceil(w1/2)
    x2 = math.floor(w1/2)
    x3 = math.ceil(w2/2)
    x4 = math.floor(w2/2)

    y1 = math.ceil(h1/2)
    y2 = math.floor(h1/2)
    y3 = math.ceil(h2/2)
    y4 = math.floor(h2/2)

    ans += rx*ry*max(x1*y1, x2*y2)
    ans += rx*ry*max(x2*y1, x1*y2)

    ans += (x-rx)*ry*max(x3*y1, x4*y2)
    ans += (x-rx)*ry*max(x4*y1, x3*y2)

    ans += rx*(y-ry)*max(x1*y3, x2*y4)
    ans += rx*(y-ry)*max(x2*y3, x1*y4)

    ans += (x-rx)*(y-ry)*max(x3*y3, x4*y4)
    ans += (x-rx)*(y-ry)*max(x4*y3, x3*y4)

    print(ans)
