import sys
from collections import deque
input = sys.stdin.readline

N = int(input())
M = int(input())

# BFS 풀이

forward = [[] for i in range(N+1)]
backward = [[] for i in range(N+1)]

for i in range(M):
    b, s = map(int, input().split())
    forward[b].append(s)
    backward[s].append(b)


def find(a):
    visited = [False for i in range(N+1)]
    cnt = 1

    forwardQ = deque()
    forwardQ.append(a)
    visited[a] = True
    while forwardQ:
        cur = forwardQ.popleft()
        for goal in forward[cur]:
            if visited[goal]:
                continue
            visited[goal] = True
            forwardQ.append(goal)
            cnt += 1

    backwardQ = deque()
    backwardQ.append(a)
    while backwardQ:
        cur = backwardQ.popleft()
        for goal in backward[cur]:
            if visited[goal]:
                continue
            visited[goal] = True
            backwardQ.append(goal)
            cnt += 1

    return N-cnt


for i in range(1, N+1):
    print(find(i))


# 플로이드 워셜 풀이

# links = [[0 for j in range(N+1)] for i in range(N+1)]
# for i in range(M):
#     a, b = map(int, input().split())
#     links[a][b] = 1

# for i in range(1, N+1):
#     links[i][i] = 1

# for k in range(1, N+1):
#     for i in range(1, N+1):
#         for j in range(1, N+1):
#             if links[i][k] and links[k][j]:
#                 links[i][j] = 1

# for i in range(1, N+1):
#     cnt = 0
#     for j in range(1, N+1):
#         if not links[i][j] and not links[j][i]:
#             cnt += 1
#     print(cnt)
