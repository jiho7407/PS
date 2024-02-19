import sys
from collections import deque
input = sys.stdin.readline

def toint(a):
    a = ord(a)
    if a >= 97:
        return a-97+26
    return a-65

capa = [[0] * 52 for i in range(52)]
flow = [[0] * 52 for i in range(52)]
links = [[] for i in range(52)]

for N in range(int(input())):
    a, b, c = input().split()
    a = toint(a)
    b = toint(b)
    c = int(c)
    capa[a][b] += c
    capa[b][a] += c
    links[a].append(b)
    links[b].append(a)

ans = 0

while True:
    pa = [-1]*52
    Q = deque()
    Q.append(0)
    while Q and pa[25] == -1:
        cur = Q.popleft()
        for goal in links[cur]:
            if capa[cur][goal] - flow[cur][goal] > 0 and pa[goal] == -1:
                Q.append(goal)
                pa[goal] = cur
                if goal == 25:
                    break
    if pa[25] == -1:
        break

    f = int(1e10)
    idx = 25
    while idx != 0:
        f = min(f, capa[pa[idx]][idx] - flow[pa[idx]][idx])
        idx = pa[idx]
    
    idx = 25
    while idx != 0:
        flow[pa[idx]][idx] += f
        flow[idx][pa[idx]] -= f
        idx = pa[idx]

    ans += f

print(ans)
    