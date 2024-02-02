import sys
input = sys.stdin.readline

N, M = map(int, input().split())
tree = [0 for i in range(2*N)]
lst = []
for i in range(N):
    lst.append(int(input()))
for i in range(N):
    tree[N+i] = lst[i]
for i in range(N-1, 0, -1):
    tree[i] = min(tree[2*i], tree[2*i+1])


for i in range(M):
    a, b = map(int, input().split())
    a += N-1
    b += N
    ans = int(1e10)
    while a < b:
        if a % 2:
            ans = min(ans, tree[a])
            a += 1
        if b % 2:
            ans = min(ans, tree[b-1])
            b -= 1
        a //= 2
        b //= 2
    print(ans)
