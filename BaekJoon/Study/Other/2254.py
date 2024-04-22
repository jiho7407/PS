import sys
from functools import cmp_to_key
input = sys.stdin.readline


def ccw(c1, c2, c3):
    v1 = (c2[0]-c1[0], c2[1]-c1[1])
    v2 = (c3[0]-c2[0], c3[1]-c2[1])
    result = v1[0]*v2[1] - v1[1]*v2[0]
    if result > 0:
        return 1
    elif result == 0:
        return 0
    else:
        return -1


def cmp(p1, p2) -> int:
    if p1[1] * p2[0] < p1[0] * p2[1]:
        return -1
    else:
        return 1


def checkin(clst):
    std = ccw(clst[-1], clst[0], P)
    for i in range(len(clst)-1):
        if std != ccw(clst[i], clst[i+1], P):
            return False
    return True


N, px, py = map(int, input().split())
P = [px, py]
points = []
for i in range(N):
    points.append([*map(int, input().split())])

ans = 0
while True:
    convex = []
    unused = []
    if len(points) < 2:
        break
    points.sort(key=lambda x: (x[1], x[0]))
    ox, oy = points[0]
    for i in range(len(points)):
        points[i][0] -= ox
        points[i][1] -= oy
    P[0] -= ox
    P[1] -= oy
    points = points[:1] + sorted(points[1:], key=cmp_to_key(cmp))
    convex.append(points[0])
    convex.append(points[1])

    for i in range(2, len(points)):
        while len(convex) >= 2:
            if ccw(convex[-2], convex[-1], points[i]) > 0:
                break
            unused.append(convex.pop())
        convex.append(points[i])

    if checkin(convex):
        ans += 1
    else:
        break

    points = unused
    for i in range(len(points)):
        points[i][0] += ox
        points[i][1] += oy
    P[0] += ox
    P[1] += oy

print(ans)
