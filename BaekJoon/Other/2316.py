import sys
from collections import deque
input = sys.stdin.readline

N, P = map(int, input().split())
V = 2*N

def toin(a):
    return 2*a-2

def toout(a):
    return 2*a-1

capa = [[0] * V for i in range(V)]
flow = [[0] * V for i in range(V)]
links = [[] for i in range(V)]

for i in range(N):
    s, e = toin(i), toout(i)
    capa[s][e] = 1
    links[s].append(e)
    links[e].append(s)

for i in range(P):
    s, e = map(int, input().split())
    capa[toout(s)][toin(e)] = 1
    capa[toout(e)][toin(s)] = 1
    links[toout(s)].append(toin(e))
    links[toout(e)].append(toin(s))
    links[toin(s)].append(toout(e))
    links[toin(e)].append(toout(s))

S = toout(1)
E = toin(2)
ans = 0

while True:
    pa = [0] * V
    Q = deque()
    Q.append(S)
    while Q and not pa[E]:
        cur = Q.popleft()
        for goal in links[cur]:
            if capa[cur][goal] - flow[cur][goal] > 0 and not pa[goal]:
                Q.append(goal)
                pa[goal] = cur
                if goal == E:
                    break
    if not pa[E]:
        break

    idx = E
    while idx != S:
        flow[pa[idx]][idx] += 1
        flow[idx][pa[idx]] -= 1
        idx = pa[idx]
    
    ans += 1

print(ans)


