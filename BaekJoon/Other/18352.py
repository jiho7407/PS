import sys
import heapq
input = sys.stdin.readline

INF = int(1e10)
N, M, K, X = map(int, input().split())
links = [[] for i in range(N+1)]
for i in range(M):
    s, e = map(int, input().split())
    links[s].append((e, 1))

dist = [INF for i in range(N+1)]


def dijkstr(start):
    Q = []
    heapq.heappush(Q, (0, start))
    dist[start] = 0
    while Q:
        curdist, cur = heapq.heappop(Q)
        if dist[cur] < curdist:
            continue
        for goal, cost in links[cur]:
            if curdist + cost < dist[goal]:
                dist[goal] = curdist + cost
                heapq.heappush(Q, (dist[goal], goal))


dijkstr(X)
stk = []
for i in range(N+1):
    if dist[i] == K:
        stk.append(i)
if stk:
    for i in stk:
        print(i)
else:
    print(-1)
