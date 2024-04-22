import sys
from collections import deque
input = sys.stdin.readline

N, P = map(int, input().split())

capa = [[0] * 401 for i in range(401)]
flow = [[0] * 401 for i in range(401)]
links = [[] for i in range(401)]

for i in range(P):
    s, e = map(int, input().split())
    capa[s][e] = 1
    links[s].append(e)
    links[e].append(s)

S = 1
E = 2
ans = 0

while True:
    pa = [0] * 401
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