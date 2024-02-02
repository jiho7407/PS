import sys
import math
sys.setrecursionlimit(int(1e5))
input = sys.stdin.readline

N = int(input())
mxlev = math.floor(math.log2(N))
root = [[0 for i in range(mxlev+1)] for j in range(N+1)]
depth = [-1 for i in range(N+1)]
graph = [[] for i in range(N+1)]

for i in range(N-1):
    s, e = map(int, input().split())
    graph[s].append(e)
    graph[e].append(s)


def dfs(start, level):
    depth[start] = level
    for goal in graph[start]:
        if depth[goal] != -1:
            continue
        root[goal][0] = start
        dfs(goal, level+1)


dfs(1, 0)

for i in range(1, mxlev+1):
    for j in range(1, N+1):
        root[j][i] = root[root[j][i-1]][i-1]


def LCA(a, b):
    if depth[a] > depth[b]:
        a, b = b, a
    for i in range(mxlev, -1, -1):  # depth 맞추기
        if depth[b] - depth[a] >= (1 << i):  # 깊이의 차이가 해당 lev 차이^2 보다 크면
            b = root[b][i]
    if a == b:
        return a
    for i in range(mxlev, -1, -1):
        if root[a][i] != root[b][i]:
            a = root[a][i]
            b = root[b][i]
    return root[a][0]


for m in range(int(input())):
    a, b = map(int, input().split())
    print(LCA(a, b))
