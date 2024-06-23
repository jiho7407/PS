N = int(input())

points = []
for i in range(N):
    points.append(list(map(int, input().split())))


def dist(p1, p2):
    return (p1[0] - p2[0])**2 + (p1[1] - p2[1])**2


for i in range(N):
    mxidx = -1
    mx = 0
    for j in range(N):
        if dist(points[i], points[j]) > mx:
            mx = dist(points[i], points[j])
            mxidx = j
    print(mxidx + 1)
