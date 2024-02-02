import sys
input = sys.stdin.readline

N, M = map(int, input().split())
tree = [[0, 0] for i in range(2*N)]
lst = []
for i in range(N):
    lst.append(int(input()))
for i in range(N):
    tree[N+i][0] = lst[i]
    tree[N+i][1] = lst[i]
for i in range(N-1, 0, -1):
    tree[i][0] = min(tree[2*i][0], tree[2*i+1][0])
    tree[i][1] = max(tree[2*i][1], tree[2*i+1][1])

for i in range(M):
    a, b = map(int, input().split())
    a += N-1
    b += N
    minans = 1e10
    maxans = 0
    while a < b:
        if a % 2:
            minans = min(minans, tree[a][0])
            maxans = max(maxans, tree[a][1])
            a += 1
        if b % 2:
            minans = min(minans, tree[b-1][0])
            maxans = max(maxans, tree[b-1][1])
            b -= 1
        a //= 2
        b //= 2
    print(minans, maxans)
