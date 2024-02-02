import sys
from collections import deque
input = sys.stdin.readline

INF = int(1e9)

N = int(input())
inlink = [0 for i in range(N+1)]
links = [[] for i in range(N+1)]
costs = [0 for i in range(N+1)]
ans = [0 for i in range(N+1)]
for i in range(N):
    cmd = [*map(int, input().split())]
    costs[i+1] = cmd[0]
    inlink[i+1] = len(cmd)-2
    for j in range(1, len(cmd)-1):
        links[cmd[j]].append(i+1)

Q = deque()
for i in range(1, N+1):
    if inlink[i] == 0:
        Q.append(i)
        ans[i] = costs[i]

while Q:
    start = Q.popleft()
    for goal in links[start]:
        inlink[goal] -= 1
        ans[goal] = max(ans[goal], ans[start] + costs[goal])
        if inlink[goal] == 0:
            Q.append(goal)

for i in range(1, N+1):
    print(ans[i])
