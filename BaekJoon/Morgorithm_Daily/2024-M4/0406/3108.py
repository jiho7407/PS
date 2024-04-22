import sys
input = sys.stdin.readline

N = int(input())
sq = [(0, 0, 0, 0)]
for i in range(N):
    x1, y1, x2, y2 = map(int, input().split())
    sq.append((x1, y1, x2, y2))

root = [i for i in range(N+1)]


def cross(A, B):
    Ax1, Ay1, Ax2, Ay2 = A
    Bx1, By1, Bx2, By2 = B
    if (Bx2 < Ax1) or (Ax2 < Bx1):
        return False
    if (By2 < Ay1) or (Ay2 < By1):
        return False
    if (Ax1 < Bx1) and (Bx2 < Ax2) and (Ay1 < By1) and (By2 < Ay2):
        return False
    if (Bx1 < Ax1) and (Ax2 < Bx2) and (By1 < Ay1) and (Ay2 < By2):
        return False
    return True


def findroot(a):
    if a == root[a]:
        return a
    root[a] = findroot(root[a])
    return root[a]


def merge(a, b):
    aroot = findroot(a)
    broot = findroot(b)
    if aroot != broot:
        if aroot < broot:
            root[broot] = aroot
        else:
            root[aroot] = broot


for i in range(N):
    for j in range(i+1, N+1):
        if cross(sq[i], sq[j]):
            merge(i, j)
for i in range(N+1):
    findroot(i)
print(len(set(root))-1)
