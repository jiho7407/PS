import sys
from collections import deque
input = sys.stdin.readline
sys.setrecursionlimit(5*int(1e5)+100)

N, M = map(int, input().split())
links = [[] for i in range(N+1)]
pa = [0] * (N+1)
scc = [0] * (N+1)
fin = [False for i in range(N+1)]
stk = []
cnt = 0
sccidx = 0

def dfs(a):
    global cnt, sccidx
    cnt += 1
    pa[a] = cnt
    stk.append(a)
    
    result = pa[a]
    for goal in links[a]:
        if not pa[goal]:
            result = min(result, dfs(goal))
        if not fin[goal]:
            result = min(result, pa[goal])
    
    if result == pa[a]:
        sccidx += 1
        while True:
            top = stk.pop()
            fin[top] = True
            scc[top] = sccidx
            if top == a:
                break
    
    return result

for i in range(M):
    s, e = map(int, input().split())
    links[s].append(e)

for i in range(1, N+1):
    if not pa[i]:
        dfs(i)
    
scclinks = [[] for i in range(sccidx+1)]
sccinlink = [0] * (sccidx+1)
for s in range(1, N+1):
    for e in links[s]:
        if scc[s] == scc[e]:
            continue
        scclinks[scc[s]].append(scc[e])
        sccinlink[scc[e]] += 1

ATM = [0] * (sccidx+1)
ans = [0] * (sccidx+1)
for i in range(1, N+1):
    v = int(input())
    ATM[scc[i]] += v
    ans[scc[i]] += v

S, P = map(int, input().split())

q = deque()

pos = [False for i in range(sccidx+1)]
pos[scc[S]] = True
for i in range(1, sccidx+1):
    if sccinlink[i] == 0:
        q.append(i)

while q:
    cur = q.popleft()
    for goal in scclinks[cur]:
        if pos[cur]:
            pos[goal] = True
            ans[goal] = max(ans[goal], ans[cur] + ATM[goal])
        sccinlink[goal] -= 1
        if sccinlink[goal] == 0:
            q.append(goal)

rests = [*map(int, input().split())]
anss = 0
for rest in rests: 
    rest = scc[rest]
    if pos[rest]:
        anss = max(anss, ans[rest])
print(anss)

