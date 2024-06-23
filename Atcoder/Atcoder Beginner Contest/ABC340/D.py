import sys
import heapq
input = sys.stdin.readline

N = int(input())
lst = [[]]
for i in range(N-1):
    lst.append([*map(int, input().split())])

pq = []
dist = [-1]*(N+1)
pq.append((0, 1))

while pq:
    curdist, cur = heapq.heappop(pq)
    if cur == N:
        continue
    cost1, cost2, goal = lst[cur]
    if dist[cur+1] == -1 or curdist + cost1 < dist[cur+1]:
        dist[cur+1] = curdist + cost1
        heapq.heappush(pq, (dist[cur+1], cur+1))
    if dist[goal] == -1 or curdist + cost2 < dist[goal]:
        dist[goal] = curdist + cost2
        heapq.heappush(pq, (dist[goal], goal))

print(dist[-1])