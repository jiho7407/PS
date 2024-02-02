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


N = int(input())
points = []
for i in range(N):
    points.append([*map(int, input().split())])
points.sort(key=lambda x: (x[1], x[0]))
px, py = points[0]
for i in range(N):
    points[i][0] -= px
    points[i][1] -= py
points = points[:1] + sorted(points[1:], key=cmp_to_key(cmp))
stk = []
stk.append(points[0])
stk.append(points[1])
for i in range(2, N):
    while len(stk) >= 2:
        if ccw(stk[-2], stk[-1], points[i]) > 0:
            break
        stk.pop()
    stk.append(points[i])

# print(points)
# print(stk)
print(len(stk))
