import sys
import heapq
input = sys.stdin.readline

N = int(input())
lst = []
for i in range(N):
    lst.append(tuple(map(int, input().split())))
lst.sort()

pq = []
ans = 0
cur = 0

for s, e in lst:
    while pq and pq[0] <= s:
        heapq.heappop(pq)
        cur -= 1
    heapq.heappush(pq, e)
    cur += 1
    ans = max(ans, cur)

print(ans)
