import sys
import heapq
input = sys.stdin.readline

M, N, K = map(int, input().split())
v, w = map(int, input().split())

links = [[] for i in range(N)]
for i in range(M):
    x, y, c = map(int, input().split())
    links[x].append((y, c))

forbids = set()
for i in range(K):
    forbids.add(tuple(map(int, input().split())))

dist = [dict() for i in range(N)] # dist[현재][이전]

pq = []
pq.append((0, v, v)) # (현재거리, 현재노드, 이전노드)
dist[v][v] = 0

while pq:
    curdist, cur, prev = heapq.heappop(pq)

    if prev in dist[cur] and curdist > dist[cur][prev]:
        continue

    for goal, cost in links[cur]:
        if (prev, cur, goal) in forbids:
            continue
        if cur in dist[goal] and dist[goal][cur] < curdist + cost:
            continue
        dist[goal][cur] = curdist + cost
        heapq.heappush(pq, (curdist + cost, goal, cur))

if dist[w]:
    print(min(dist[w].values()))
else:
    print(-1)