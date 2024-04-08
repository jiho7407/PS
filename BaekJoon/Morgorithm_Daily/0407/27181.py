import sys
import heapq
input = sys.stdin.readline

N, M, T = map(int, input().split())
links = [[] for _ in range(N+1)]
mxs = 0
for i in range(M):
    u, v, t, s = map(int, input().split())
    mxs = max(mxs, s)
    links[u].append((v, t, s))
    links[v].append((u, t, s))

INF = int(1e11)
left = 0
right = mxs


def dijk(a):
    PQ = []
    PQ.append((0, 1))
    dist = [INF] * (N+1)
    dist[1] = 0
    while PQ:
        curcost, cur = heapq.heappop(PQ)
        if cur == N:
            return dist[cur] <= T
        if curcost > T:
            continue
        if dist[cur] < curcost:
            continue
        for goal, time, uncom in links[cur]:
            time += max(0, uncom-a)
            if curcost + time >= dist[goal]:
                continue
            dist[goal] = curcost + time
            heapq.heappush(PQ, (dist[goal], goal))
    return False


ans = -1
while left <= right:
    mid = (left + right)//2
    res = dijk(mid)
    if res:
        ans = mid
        right = mid-1
    else:
        left = mid+1

print(ans)
