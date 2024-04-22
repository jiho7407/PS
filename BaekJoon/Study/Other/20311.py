import sys

input = sys.stdin.readline

N, K = map(int, input().split())
templst = [*map(int, input().split())]

lst = []

for i in range(K):
    lst.append([i + 1, templst[i]])

lst.sort(key=lambda x: x[1], reverse=True)
ans = [0] * N

curidx = 0
for i in range(N):
    cmd = lst[curidx][0]
    lst[curidx][1] -= 1
    if lst[curidx][1] == 0:
        curidx += 1
    if i * 2 < N:
        ans[(i * 2)] = cmd
    else:
        ans[(i * 2) - N + ((N + 1) % 2)] = cmd

pos = True
for i in range(N - 1):
    if ans[i] == ans[i + 1]:
        pos = False
        break

if pos:
    print(*ans)
else:
    print(-1)
