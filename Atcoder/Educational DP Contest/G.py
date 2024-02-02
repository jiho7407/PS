import sys
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().split())
links = [[] for i in range(N+1)]

inlinks = [0] * (N+1)
dists = [0] * (N+1)

for i in range(M):
    x, y = map(int, input().split())
    links[x].append(y)
    inlinks[y] += 1

Q = deque()

for i in range(1, N+1):
    if inlinks[i] == 0:
        Q.append(i)

while Q:
    cur = Q.popleft()
    for goal in links[cur]:
        inlinks[goal] -= 1
        dists[goal] = max(dists[goal], dists[cur]+1)
        if inlinks[goal] == 0:
            Q.append(goal)

print(max(dists))