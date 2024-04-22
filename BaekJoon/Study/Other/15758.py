import sys
import heapq
import copy
input = sys.stdin.readline

N, M = map(int, input().split())

query = []
for i in range(M):
    query.append(tuple(map(int, input().split())))


def check(a):
    inlink = [0] * (N+1)
    links = [[] for i in range(N+1)]
    for i in range(a):
        for j in range(1, query[i][0]):
            s, e = query[i][j], query[i][j+1]
            inlink[e] += 1
            links[s].append(e)

    result = []

    Q = []
    for i in range(1, N+1):
        links[i].sort()
        if inlink[i] == 0:
            heapq.heappush(Q, i)

    while Q:
        cur = heapq.heappop(Q)
        result.append(cur)
        for goal in links[cur]:
            inlink[goal] -= 1
            if inlink[goal] == 0:
                heapq.heappush(Q, goal)

    if max(inlink):
        return False
    return result


left, right = 0, M-1
ans = []
while left <= right:
    mid = (left+right)//2
    result = check(mid)
    if result:
        ans = copy.deepcopy(result)
        left = mid+1
    else:
        right = mid - 1

print(*ans)
