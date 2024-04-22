import sys
import math
input = sys.stdin.readline
sys.setrecursionlimit(int(1e5))

N = int(input())
mxlev = math.ceil(math.log2(N))

edges = [[] for i in range(N+1)]
for i in range(N-1):
    A, B, C = map(int, input().split())
    edges[A].append((B, C))
    edges[B].append((A, C))

def maketree(a, d):
    for goal, cost in edges[a]:
        if depth[goal] != -1:
            continue
        depth[goal] = d+1
        root[goal][0] = a
        mnroad[goal][0] = cost
        mxroad[goal][0] = cost
        maketree(goal, d+1)

depth = [-1 for i in range(N+1)]
root = [[0]*mxlev for i in range(N+1)]
mnroad = [[0]*mxlev for i in range(N+1)]
mxroad = [[0]*mxlev for i in range(N+1)]

depth[1] = 0
maketree(1, 0)

for i in range(1, mxlev):
    for j in range(1, N+1):
        root[j][i] = root[root[j][i-1]][i-1]
        mnroad[j][i] = min(mnroad[j][i-1], mnroad[root[j][i-1]][i-1])
        mxroad[j][i] = max(mxroad[j][i-1], mxroad[root[j][i-1]][i-1])

def LCA(a, b):
    mn = int(1e6)
    mx = 0
    
    if depth[a] > depth[b]:
        a, b = b, a

    for i in range(mxlev-1, -1, -1):
        if depth[b] - depth[a] >= (1<<i):
            mn = min(mn, mnroad[b][i])
            mx = max(mx, mxroad[b][i])
            b = root[b][i]

    if a == b:
        return mn, mx
    
    for i in range(mxlev-1, -1, -1):
        if root[a][i] != root[b][i]:
            mn = min(mn, mnroad[a][i])
            mx = max(mx, mxroad[a][i])
            a = root[a][i]

            mn = min(mn, mnroad[b][i])
            mx = max(mx, mxroad[b][i])
            b = root[b][i]
    
    mn = min(mn, mnroad[a][0])
    mx = max(mx, mxroad[a][0])
    mn = min(mn, mnroad[b][0])
    mx = max(mx, mxroad[b][0])

    return mn, mx

for K in range(int(input())):
    D, E = map(int, input().split())
    print(*LCA(D, E))