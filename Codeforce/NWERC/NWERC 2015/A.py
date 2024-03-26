import sys
import heapq
input = sys.stdin.readline

N, M = map(int, input().split())
lst = []
for i in range(N):
    lst.append(tuple(map(int, input().split())))

lst.sort(key= lambda x:(x[0], x[1]))
pq = []

ans = 0
for i in range(N):
    s, d = lst[i]
    e = s + d
    while pq and pq[0] + M < s:
        heapq.heappop(pq)
    if pq and pq[0] <= s:
        heapq.heappop(pq)
        ans += 1
    heapq.heappush(pq, e)

print(ans)