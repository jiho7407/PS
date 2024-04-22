import sys
input = sys.stdin.readline
sys.setrecursionlimit(5*int(1e4))

class unionFind():
    def __init__(self, N) -> None:
        self.root = [i for i in range(N+1)]
        self.cnnt = 0
        self.links = [[] for i in range(N+1)]
    
    def findroot(self, a):
        if a == self.root[a]:
            return a
        self.root[a] = self.findroot(self.root[a])
        return self.root[a]
    
    def merge(self, a, b):
        a = self.findroot(a)
        b = self.findroot(b)
        if a == b:
            return False

        if a < b:
            self.root[b] = a
        else:
            self.root[a] = b
        self.cnnt += 1

        return True


class segtree():
    def __init__(self, N):
        self.treeN = N+1
        self.tree = [0] * (2*self.treeN)

    def maketree(self):
        for i in range(self.treeN-1, 0, -1):
            self.tree[i] = self.tree[i*2] + self.tree[i*2+1]
    
    def update(self, idx, v):
        idx += self.treeN
        self.tree[idx] = v
        idx //= 2
        while idx:
            self.tree[idx] = self.tree[idx*2] + self.tree[idx*2+1]
            idx //= 2
    
    def query(self, s, e):
        s += self.treeN
        e += self.treeN+1
        temp = 0
        while s<e:
            if s%2:
                temp += self.tree[s]
                s += 1
            if e%2:
                e -= 1
                temp += self.tree[e]
            s //= 2
            e //= 2
        return temp
    
class HLD():
    def __init__(self, N, links):
        self.treeN = N+1

        self.links = links
        self.tree = segtree(N)
        self.cnt = [0] * (self.treeN)
        self.depth = [0] * (self.treeN)
        self.par = [i for i in range(self.treeN)]
        self.hldidx = [i for i in range(self.treeN)]
        self.head = [i for i in range(self.treeN)]
        self.idx = 0

        self.visited = [False for i in range(self.treeN)]

    def euler(self, a, lev):
        self.visited[a] = True
        temp = 1
        self.depth[a] = lev
        for goal in self.links[a]:
            if self.par[a] == goal:
                continue
            self.par[goal] = a
            temp += self.euler(goal, lev+1)
        self.cnt[a] += temp
        self.links[a].sort(key = lambda x: -self.cnt[x])
        return temp

    def heavylight(self, a):
        self.idx += 1
        self.hldidx[a] = self.idx
        heavy = True
        for goal in self.links[a]:
            if self.par[a] == goal:
                continue
            if heavy:
                self.head[goal] = self.head[a]
                heavy = False
            self.heavylight(goal)
    
    def build(self, lst):
        for i in range(1, self.treeN):
            if self.visited[i]:
                continue
            self.euler(a=i, lev=0)
            self.heavylight(i)
        
        for i in range(len(lst)):
            self.tree.tree[self.treeN+self.hldidx[i+1]] = lst[i]
        self.tree.maketree()

    def solve(self, a, b):
        temp = 0
        while self.head[a] != self.head[b]:
            if self.depth[self.head[a]] > self.depth[self.head[b]]:
                a, b = b, a
            temp += self.tree.query(s=self.hldidx[self.head[b]], e=self.hldidx[b])
            b = self.par[self.head[b]]
        if self.depth[a] > self.depth[b]:
            a, b = b, a
        temp += self.tree.query(s=self.hldidx[a], e=self.hldidx[b])
        return temp

    
N = int(input())
lst = [*map(int, input().split())]
query = [tuple(input().split()) for q in range(int(input()))]

UF = unionFind(N)
for cmd, a, b in query:
    if UF.cnnt == N-1:
        break
    if cmd != "bridge":
        continue
    a = int(a)
    b = int(b)
    if UF.merge(a, b):
        UF.links[a].append(b)
        UF.links[b].append(a)

hld = HLD(N, UF.links)
hld.build(lst)

UF = unionFind(N)
for cmd, a, b in query:
    a = int(a)
    b = int(b)
    if cmd == "bridge":
        result = UF.merge(a, b)
        if result:
            print("yes")
        else:
            print("no")

    elif cmd == "penguins":
        hld.tree.update(hld.hldidx[a], b)
    
    else:
        if UF.findroot(a) != UF.findroot(b):
            print("impossible")
            continue
        print(hld.solve(a, b))