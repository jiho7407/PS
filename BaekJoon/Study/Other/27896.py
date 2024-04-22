import heapq

N, M = map(int, input().split())
lst = [*map(int, input().split())]
cur = 0
pq = []
ans = 0
for i in range(N):
    cmd = lst[i]
    if cur + cmd < M:
        cur += cmd
        heapq.heappush(pq, cmd*-1)
        continue
    ans += 1
    heapq.heappush(pq, cmd*-1)
    cur += cmd
    cur += heapq.heappop(pq)*2
print(ans)
