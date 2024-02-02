import sys
import heapq
input = sys.stdin.readline

N, M = map(int, input().split())

in_line_lst = [0 for i in range(N+1)]
link_lst = [[] for i in range(N+1)]

for i in range(M):
    s, e = map(int, input().split())
    in_line_lst[e] += 1
    link_lst[s].append(e)

PQ = []
for i in range(1, N+1):
    if in_line_lst[i] == 0:
        heapq.heappush(PQ, i)

while PQ:
    cur = heapq.heappop(PQ)
    print(cur, end=' ')
    for goal in link_lst[cur]:
        in_line_lst[goal] -= 1
        if in_line_lst[goal] == 0:
            heapq.heappush(PQ, goal)
