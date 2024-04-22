import sys
import heapq
input = sys.stdin.readline

TC = int(input())

N, M, K = map(int, input().split())
link = [[] for i in range(N+1)]
for i in range(K):
    u, v, c, d = map(int, input().split())
    link[u].append((v, c, d))

for i in range(N+1):
    link[i].sort(key = lambda x: x[2]) # 가격이랑 시간중 뭐 정렬이 더 빠를까

pq = []
pq.append((0, 0, 1)) #시간, 가격, 위치

mx = int(1e10)

dists = [[mx for j in range(M+1)] for i in range(N+1)] # dists[공항][가격] 해당 공항의 해당 가격에 대해 제일 빠른거

while pq:
    curtime, curcost, cur = heapq.heappop(pq)

    if dists[cur][curcost] < curtime:
        continue

    for goal, cost, time in link[cur]:
        if curcost + cost > M:
            continue
        if dists[goal][curcost+cost] <= curtime + time:
            continue
        for i in range(curcost+cost, M+1):
            if dists[goal][i] < curtime+time:
                break
            dists[goal][i] = curtime+time
        heapq.heappush(pq, (curtime+time, curcost + cost, goal))

ans = mx
for i in range(M+1):
    ans = min(ans, dists[N][i])
if ans == mx:
    print("Poor KCM")
else:
    print(ans)

