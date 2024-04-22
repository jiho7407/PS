import sys
input = sys.stdin.readline


def binmatch(a):
    visited[a] = True
    for b in links[a]:
        if not B[b]:
            A[a] = b
            B[b] = a
            return True
    for b in links[a]:
        if not visited[B[b]] and binmatch(B[b]):
            A[a] = b
            B[b] = a
            return True
    return False


N, M = map(int, input().split())
A = [0] * (N+1)
B = [0] * (M+1)
links = [[] for i in range(2*N+1)]

for i in range(1, N+1):
    num, *lst = map(int, input().split())
    links[i] = lst

ans = 0
for a in range(1, N+1):
    for j in range(2):
        visited = [False] * (2*N+1)
        result = binmatch(a)
        if result:
            ans += 1
    if ans == M:
        break

print(ans)
