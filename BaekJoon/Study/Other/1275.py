import sys
input = sys.stdin.readline

N, M = map(int, input().split())
tree = [0 for i in range(2*N)]
lst = [*map(int, input().split())]
for i in range(N):
    tree[N+i] = lst[i]
for i in range(N-1, 0, -1):
    tree[i] = tree[2*i] + tree[2*i+1]

for i in range(M):
    x, y, a, b = map(int, input().split())
    if x > y:
        x, y = y, x
    x += N-1
    y += N
    ans = 0
    while x < y:
        if x % 2:
            ans += tree[x]
            x += 1
        if y % 2:
            ans += tree[y-1]
            y -= 1
        x //= 2
        y //= 2
    print(ans)
    lst[a-1] = b
    a += N-1
    tree[a] = b
    while a > 1:
        a //= 2
        tree[a] = tree[2*a] + tree[2*a+1]
