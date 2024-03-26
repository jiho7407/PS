import heapq

N, P = map(int,input().split())

workers = []
for i in range(N):
    workers.append(tuple(map(int, input().split())))

workers.sort(key = lambda x: (x[0], x[1]))

pq = []
mx = 0
ans = 0
for i in range(N):
    s, e = workers[i]

    while pq and pq[0] < s:
        if len(pq) == mx:
            ans += e - workers[i-1][0]
        heapq.heappop(pq)
    heapq.heappush(pq, e)

    if len(pq) > mx:
        mx = len(pq)
        ans = 0

    print(mx, ans)
# 1 2 3
# 1 2 3 4 5
#   2 3 4 5 6 7
#       4 5 6