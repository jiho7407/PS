import sys
input = sys.stdin.readline

N, M = map(int, input().split())

roots = [*range(N)]
links = []
for i in range(M):
    links.append([*map(int, input().split())])


def findroot(a):
    while a != roots[a]:
        a = roots[a]
    return a


def merge(a, b):
    aroot = findroot(a)
    broot = findroot(b)
    if aroot != broot:
        if aroot > broot:
            roots[aroot] = broot
        else:
            roots[broot] = aroot
        return False
    return True


def solve():
    for i in range(M):
        s, e = links[i]
        if merge(s, e):
            return i+1
    return 0


print(solve())
