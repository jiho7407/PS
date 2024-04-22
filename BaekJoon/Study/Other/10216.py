import sys
import math
input = sys.stdin.readline


def dist(a, b):
    ax, ay = enemy[a]
    bx, by = enemy[b]
    return math.sqrt((ax-bx)**2 + (ay-by)**2)


def findroot(a):
    if a == root[a]:
        return a
    root[a] = findroot(root[a])
    return root[a]


def merge(aroot, broot):
    if aroot != broot:
        if aroot < broot:
            root[broot] = aroot
        else:
            root[aroot] = broot


for TC in range(int(input())):
    N = int(input())
    enemy = []
    radius = []
    for i in range(N):
        x, y, R = map(int, input().split())
        enemy.append([x, y])
        radius.append(R)

    root = [i for i in range(N)]

    ans = N
    for i in range(N-1):
        for j in range(i+1, N):
            iroot = findroot(i)
            jroot = findroot(j)
            if iroot == jroot:
                continue
            if dist(i, j) <= radius[i] + radius[j]:
                merge(iroot, jroot)
                ans -= 1

    print(ans)
