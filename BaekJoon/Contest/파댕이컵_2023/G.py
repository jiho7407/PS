import sys
input = sys.stdin.readline

N, M, K = map(int, input().split())
road = [[] for i in range(N+1)]
for i in range(M):
    u, v, c = map(int, input().split())
    road[u].append([v, c])
    road[v].append([u, c])
