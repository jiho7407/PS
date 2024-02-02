import sys
input = sys.stdin.readline

N = int(input())
lst = [*map(int, input().split())]
tree = [0 for i in range(2*N)]
for i in range(N):
    tree[N+i] = lst[i]
for i in range(N-1, 0, -1):
    tree[i] = min(tree[2*i], tree[2*i+1])

for i in range(int(input())):
    q, a, b = map(int, input().split())
    if q == 1:
        temp, lst[a-1] = lst[a-1], b
        idx = N+a-1
        tree[idx] = b
        idx //= 2
        while idx >= 1:
            tree[idx] = min(tree[idx*2], tree[idx*2+1])
            idx //= 2
    elif q == 2:
        k = a
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
        while True:
            if lst[k-1] == ans:
                print(k)
                break
            k += 1
