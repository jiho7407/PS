import sys
import math
sys.setrecursionlimit(int(1e5)+1000)
input = sys.stdin.readline

N, M = map(int, input().split())

links = []
for i in range(M):
    links.append(tuple(map(int, input().split())))

links.sort(key = lambda x:x[2])

mxlev = math.ceil(math.log2(N))
tree = [[i for j in range(mxlev) ] for i in range(2*N)]
root = [i for i in range(2*N)]

def findroot(a):
    if a == root[a]:
        return a
    root[a] = findroot(root[a])
    return root[a]

idx = N+1
deg = [0]*(2*N)
cnt = [0] + ([1]*N) + ([0]*(N-1))

def merge(a, b, c):
    global idx
    a = findroot(a)
    b = findroot(b)
    if a == b:
        return False
    
    root[a] = idx
    root[b] = idx
    tree[a][0] = idx
    tree[b][0] = idx
    deg[idx] = c
    cnt[idx] = cnt[a] + cnt[b]
    idx += 1
    return True

connect = 0

for s, e, c in links:
    if connect == N-1:
        break
    
    if merge(s, e, c):
        connect += 1

for i in range(1, mxlev):
    for j in range(1, 2*N):
        tree[j][i] = tree[tree[j][i-1]][i-1]

depth = [1] * (2*N)

for i in range(1, 2*N):
    idx = i
    temp = 0
    for j in range(mxlev-1, -1, -1):
        if tree[idx][j] == findroot(idx):
            continue
        idx = tree[idx][j]
        temp += (1<<j)
    depth[i]+=temp

def LCA(a, b):
    if depth[a] > depth[b]:
        a, b = b, a
    
    for i in range(mxlev-1, -1, -1):
        if depth[b] - depth[a] >= (1<<i):
            b = tree[b][i]

    if a == b:
        return a
    
    for i in range(mxlev-1, -1, -1):
        if tree[a][i] == tree[b][i]:
            continue
        a = tree[a][i]
        b = tree[b][i]
    if findroot(a) != findroot(b):
        return False
    return tree[a][0]

for Q in range(int(input())):
    x, y = map(int, input().split())
    lca = LCA(x, y)
    if not lca:
        print(-1)
        continue
    print(deg[lca], cnt[lca])