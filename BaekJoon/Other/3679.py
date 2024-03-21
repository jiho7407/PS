import sys
import math

input = sys.stdin.readline

for TC in range(int(input())):
    lst = [*map(int, input().split())]
    points = []
    for i in range(lst[0]):
        points.append([i, lst[2 * i + 1], lst[2 * i + 2]])
    points.sort(key=lambda x: (x[2], x[1]))
    px, py = points[0][1], points[0][2]
    for i in range(len(points)):
        points[i][1] -= px
        points[i][2] -= py

    points.sort(
        key=lambda x: (
            math.atan2(x[2], x[1]),
            (x[1] * x[1] + x[2] * x[2]),
        )
    )

    idx = 1
    while math.atan2(points[-idx][2], points[-idx][1]) == math.atan2(
        points[-(idx + 1)][2], points[-(idx + 1)][1]
    ):
        idx += 1

    for i in range(len(points) - idx):
        print(points[i][0], end=" ")
    for i in range(1, idx + 1):
        print(points[-i][0], end=" ")
    print()
