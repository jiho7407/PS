import sys
input = sys.stdin.readline


def binmatch(a):
    visited[a] = True
    for b in links[a]:
        if not B[b] or (not visited[B[b]] and binmatch(B[b])):
            A[a] = b
            B[b] = a
            return True
    return False


N, M = map(int, input().split())
A = [0] * (N+1)
B = [0] * (M+1)
links = [[] for i in range(N+1)]

for i in range(N):
    num, *lst = map(int, input().split())
    for j in lst:
        links[i+1].append(j)

ans = 0
for a in range(1, N+1):
    if not A[a]:
        visited = [False] * (N+1)
        result = binmatch(a)
        if result:
            ans += 1

print(ans)
