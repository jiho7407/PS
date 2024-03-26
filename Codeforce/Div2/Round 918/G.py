import sys
import heapq
input = sys.stdin.readline

INF = 1e12
for TC in range(int(input())):
    N, M = map(int, input().split())
    links = [[] for i in range(N+1)]
    for i in range(M):
        u, v, w = map(int, input().split())
        links[u].append([v, w])
        links[v].append([u, w])
    slowfactor = [0] + [*map(int, input().split())]

    dp = [[INF for i in range(1001)]for j in range(N+1)]
    pq = []
    pq.append([0, 1, slowfactor[1]])  # 현재 거리, 현재 도시, 자전거 요소

    while pq:
        curdist, curnode, cursf = heapq.heappop(pq)
        if curnode == N:
            print(curdist)
            break

        for goal, weight in links[curnode]:
            if dp[goal][cursf] > curdist + weight*cursf:
                dp[goal][cursf] = curdist + weight*cursf
                heapq.heappush(
                    pq, [dp[goal][cursf], goal, min(slowfactor[goal], cursf)])
