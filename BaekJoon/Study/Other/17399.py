import sys
import math
input = sys.stdin.readline
sys.setrecursionlimit(int(1e5)+1000)

N = int(input())
links = [[] for i in range(N+1)]

for i in range(N-1):
    x, y = map(int, input().split())
    links[x].append(y)
    links[y].append(x)

mxlev = math.ceil(math.log2(N))
tree = [[0] * mxlev for i in range(N+1)]

depth = [0] * (N+1)


def maketree(a, parent, lev):
    depth[a] = lev
    for goal in links[a]:
        if goal == parent:
            continue
        tree[goal][0] = a
        maketree(goal, a, lev+1)


maketree(1, 0, 0)

for i in range(1, mxlev):
    for j in range(1, N+1):
        tree[j][i] = tree[tree[j][i-1]][i-1]


def LCA(a, b):
    if depth[a] > depth[b]:
        a, b = b, a

    for i in range(mxlev-1, -1, -1):
        if (depth[b] - depth[a]) >= (1 << i):
            b = tree[b][i]

    if a == b:
        return a

    for i in range(mxlev-1, -1, -1):
        if tree[a][i] != tree[b][i]:
            a = tree[a][i]
            b = tree[b][i]

    return tree[a][0]


def dist(a, b):
    lca = LCA(a, b)
    return depth[a] + depth[b] - 2*depth[lca]


def findcc(a, b, d):
    if depth[a] > depth[b]:
        a, b = b, a
    for i in range(mxlev-1, -1, -1):
        if d >= (1 << i):
            b = tree[b][i]
            d -= (1 << i)
    return b


def solve(a, b, c):
    d = dist(a, b)
    if d % 2:
        return False
    d //= 2
    cc = findcc(a, b, d)
    if dist(cc, c) == d:
        print(cc)
        return True
    else:
        return False


for TC in range(int(input())):
    a, b, c = map(int, input().split())

    if solve(a, b, c):
        continue
    if solve(b, c, a):
        continue
    if solve(c, a, b):
        continue
    print(-1)
