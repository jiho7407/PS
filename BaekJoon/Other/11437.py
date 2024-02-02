import sys
sys.setrecursionlimit(int(1e5))
input = sys.stdin.readline

N = int(input())
root = [0 for i in range(N+1)]
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
        root[goal] = start
        dfs(goal, level+1)


dfs(1, 0)


def LCA(a, b):
    while depth[a] != depth[b]:
        if depth[a] > depth[b]:
            a = root[a]
        else:
            b = root[b]
    while a != b:
        a = root[a]
        b = root[b]
    return a


for m in range(int(input())):
    a, b = map(int, input().split())
    print(LCA(a, b))
