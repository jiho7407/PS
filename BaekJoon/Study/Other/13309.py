import sys
sys.setrecursionlimit(2*int(1e5)+1000)
input = sys.stdin.readline

N, Q = map(int, input().split())

sz = [1 for i in range(N+1)]
depth = [0 for i in range(N+1)]
par = [i for i in range(N+1)]
front = [i for i in range(N+1)]
HLD = [0 for i in range(N+1)]
links = [[] for i in range(N+1)]

for i in range(1, N):
    cmd = int(input())
    par[i+1] = cmd
    links[cmd].append(i+1)

def maketree(a, lev):
    for goal in links[a]:
        depth[goal] = lev+1
        maketree(goal, lev+1)
        sz[a] += sz[goal]
    links[a].sort(key = lambda x: sz[x], reverse= True)


idx = 0
def euler(a):
    global idx
    idx += 1
    HLD[a] = idx
    for tempidx, goal in enumerate(links[a]):
        if tempidx == 0:
            front[goal] = front[a]
        euler(goal)


maketree(1, 0)
euler(1)

treeN = N+1
segtree = [1] * (2*treeN)

def update(idx):
    idx = HLD[idx]
    idx += treeN
    while idx:
        segtree[idx] = 0
        idx //= 2

def query(a, b):
    a += treeN
    b += treeN+1
    temp = 1
    while a < b:
        if a%2:
            temp = min(temp, segtree[a])
            a += 1
        if b%2:
            b -= 1
            temp = min(temp, segtree[b])
        a //= 2
        b //= 2
    return temp

def solve(a, b):
    temp = 1
    while front[a] != front[b]: # 같은 선분에 올떄까지
        if temp == 0:
            return 0
        if depth[a] > depth[b]:
            a, b = b, a
        temp = min(temp, query(HLD[front[b]], HLD[b]))
        b = par[front[b]]
    if depth[a] > depth[b]:
        a, b = b, a
    if a == b:
        return temp
    temp = min(temp, query(HLD[a]+1, HLD[b]))
    return temp
        
for q in range(Q):
    b, c, d = map(int, input().split())
    if d == 0:
        if solve(b, c):
            print("YES")
        else:
            print("NO")
    else:
        bb, cc = b, c
        if solve(b, c):
            print("YES")
            update(bb)
        else:
            print("NO")
            update(cc)