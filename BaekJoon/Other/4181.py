import sys
from functools import cmp_to_key
input = sys.stdin.readline


def ccw(c1, c2, c3):
    v1 = (c2[0]-c1[0], c2[1]-c1[1])
    v2 = (c3[0]-c2[0], c3[1]-c2[1])
    result = v1[0]*v2[1] - v1[1]*v2[0]
    return result


N = int(input())
points = []
for i in range(N):
    x, y, c = input().split()
    points.append([int(x), int(y)])
points.sort()

ans = -2
bot = []
for i in range(N):
    while len(bot) >= 2:
        if ccw(bot[-2], bot[-1], points[i]) >= 0:
            break
        bot.pop()
    bot.append(points[i])

top = []
for i in range(N-1, -1, -1):
    while len(top) >= 2:
        if ccw(top[-2], top[-1], points[i]) >= 0:
            break
        top.pop()
    top.append(points[i])

print(len(bot) + len(top) - 2)
for i in range(len(bot)):
    print(*bot[i])
for i in range(1, len(top)-1):
    print(*top[i])
