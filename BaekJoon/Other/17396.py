import sys
import heapq
input = sys.stdin.readline

INF = int(1e20)
N, M = map(int, input().split())
sight = [*map(int, input().split())]
sight[-1] = 0
links = [[] for i in range(N)]
for i in range(M):
    s, e, c = map(int, input().split())
    if sight[s] == 1 or sight[e] == 1:
        continue
    links[e].append([s, c])
    links[s].append([e, c])

dist = [INF for i in range(N)]
dist[0] = 0
visited = [False for i in range(N)]

PQ = []
heapq.heappush(PQ, (0, 0))  # 비용, 점
while PQ:
    curdist, cur = heapq.heappop(PQ)
    if cur == N-1:
        break
    if visited[cur]:
        continue
    for goal, cost in links[cur]:
        temp = curdist + cost
        if temp > dist[goal]:
            continue
        dist[goal] = temp
        heapq.heappush(PQ, (temp, goal))
    visited[cur] = True

if dist[-1] == INF:
    print(-1)
else:
    print(dist[-1])
