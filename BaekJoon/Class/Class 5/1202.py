import sys
import heapq

input = sys.stdin.readline

N, K = map(int, input().split())

jewels = []
for i in range(N):
    jewels.append([*map(int, input().split())])
jewels.sort()

bagheap = []
for i in range(K):
    c = int(input())
    heapq.heappush(bagheap, c)

ans = 0
idx = 0
jewelpq = []
for i in range(K):
    weight = heapq.heappop(bagheap)
    while idx < N:
        if jewels[idx][0] > weight:
            break
        heapq.heappush(jewelpq, -jewels[idx][1])
        idx += 1
    if jewelpq:
        ans -= heapq.heappop(jewelpq)
print(ans)
