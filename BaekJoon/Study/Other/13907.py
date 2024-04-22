import sys
import heapq
input = sys.stdin.readline


N, M, K = map(int, input().split())
S, D = map(int, input().split())

dp = [[0] * (M+1) for i in range(N+1)] # dp[현재 도시][사용 도로 개수]

links = [[] for i in range(N+1)]
for i in range(M):
    a, b, w = map(int, input().split())
    links[a].append((b, w))
    links[b].append((a, w))

taxes = []
for i in range(K):
    taxes.append(int(input()))

pq = []
pq.append((0, S, 0)) # (현재거리, 현재 도시, 지나간 도로 수)

while pq:
    curdist, cur, roads = heapq.heappop(pq)

    if dp[cur][roads] < curdist:
        continue

    for goal, cost in links[cur]:
        if dp[goal][roads+1] and dp[goal][roads+1] < curdist + cost:
            continue
        
        for i in range(roads+1, M+1):
            if dp[goal][i] and dp[goal][i] <= curdist+cost:
                break
            dp[goal][i] = curdist + cost
        
        if roads >= M-1:
            continue
        heapq.heappush(pq, (dp[goal][roads+1], goal, roads+1))

lst = dp[D][1:]
for i in range(M):
    if lst[i] == 0:
        lst[i] += 10000000

print(min(lst))
for cmd in taxes:
    for i in range(M):
        lst[i] += (i+1) * cmd
    print(min(lst))