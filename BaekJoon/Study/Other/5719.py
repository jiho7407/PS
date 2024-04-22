import sys
import heapq
from collections import deque
input = sys.stdin.readline

while True:
    N, M = map(int, input().split())

    if N+M == 0:
        break
    
    S, D = map(int, input().split())

    roads = [dict() for i in range(N)]
    back = [[] for i in range(N)]

    for i in range(M):
        u, v, p = map(int, input().split())
        roads[u][v] = p
        back[v].append(u)

    dist = [-1] * N
    dist[S] = 0

    pq = []
    pq.append((0, S))

    while pq:
        curdist, cur = heapq.heappop(pq)
        if dist[cur] != -1 and dist[cur] < curdist:
            continue

        for goal in roads[cur].keys():
            cost = roads[cur][goal]
            if dist[goal] != -1 and dist[goal] <= curdist + cost:
                continue
            dist[goal] = curdist + cost
            heapq.heappush(pq, (dist[goal], goal))

    Q = deque()
    Q.append(D)

    while Q:
        cur = Q.popleft()
        for origin in back[cur]:
            if cur in roads[origin] and dist[origin] + roads[origin][cur] == dist[cur]:
                del roads[origin][cur]
                Q.append(origin)


    dist = [-1] * N
    dist[S] = 0

    pq = []
    pq.append((0, S))

    while pq:
        curdist, cur = heapq.heappop(pq)
        if dist[cur] != -1 and dist[cur] < curdist:
            continue

        for goal in roads[cur].keys():
            cost = roads[cur][goal]
            if dist[goal] != -1 and dist[goal] <= curdist + cost:
                continue
            dist[goal] = curdist + cost
            heapq.heappush(pq, (dist[goal], goal))

    print(dist[D])