import sys
import heapq
input = sys.stdin.readline

N = int(input())
lst = []

for i in range(N):
    a, b = map(int, input().split())
    if b < a:
        a, b = b, a
    lst.append([a, b])

lst.sort(key=lambda x: x[1])
d = int(input())

PQ = []
ans = 0
for i in range(N):
    curs, cure = lst[i]
    heapq.heappush(PQ, curs)
    while PQ and PQ[0] + d < cure:
        heapq.heappop(PQ)
    ans = max(ans, len(PQ))
print(ans)
