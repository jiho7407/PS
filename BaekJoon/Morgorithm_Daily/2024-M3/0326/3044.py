import sys
from collections import deque

input = sys.stdin.readline

N, M = map(int, input().split())
links = [[] for i in range(N + 1)]
inlink = [0] * (N + 1)
ways = [0] * (N + 1)

for i in range(M):
    s, e = map(int, input().split())
    links[s].append(e)
    inlink[e] += 1

visited = [False] * (N + 1)
visited[1] = True


def dfs(a):
    for g in links[a]:
        if visited[g]:
            continue
        visited[g] = True
        dfs(g)


dfs(1)

if not visited[2]:
    print(0)
    sys.exit()

for i in range(1, N + 1):
    if visited[i]:
        continue
    for g in links[i]:
        inlink[g] -= 1
    links[i] = []

if inlink[1] != 0:
    print("inf")
    sys.exit()

newM = sum(inlink)
Q = deque()
Q.append(1)
ways[1] = 1

mod = int(1e9)
overmod = False
vis = []

while Q:
    cur = Q.popleft()
    for goal in links[cur]:
        ways[goal] += ways[cur]
        if ways[goal] >= mod:
            ways[goal] %= mod
            overmod = True
        inlink[goal] -= 1
        newM -= 1
        if inlink[goal] == 0:
            Q.append(goal)

for i in range(1, N + 1):
    if not inlink[i]:
        continue
    Q.append(i)
    while Q:
        cur = Q.popleft()
        for goal in links[cur]:
            if goal == 2:
                print("inf")
                sys.exit()
            inlink[goal] -= 1
            if inlink[goal] == 0:
                Q.append(goal)

ans = ways[2]
if overmod:
    print("0" * (9 - len(str(ans))), end="")
    print(ans)
else:
    print(ans)
