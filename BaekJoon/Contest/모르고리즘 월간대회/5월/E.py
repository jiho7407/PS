import sys
from bisect import bisect_left

input = sys.stdin.readline

N = int(input())
points = []
for i in range(N):
    points.append(list(map(int, input().split())))

for Q in range(int(input())):
    a = float(input())
    idx = bisect_left(points, [a, 0])
    pos = points[idx][1] - points[idx - 1][1]
    if pos == 0:
        print(0)
    elif pos > 0:
        print(1)
    else:
        print(-1)
