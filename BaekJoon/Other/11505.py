import sys
input = sys.stdin.readline

mod = int(1e9)+7
N, M, K = map(int, input().split())
tree = [0 for i in range(2*N)]
lst = []
for i in range(N):
    lst.append(int(input()))
for i in range(N):
    tree[N+i] = lst[i]
for i in range(N-1, 0, -1):
    tree[i] = tree[2*i] * tree[2*i+1]
    tree[i] %= mod

for i in range(M+K):
    q, a, b = map(int, input().split())
    if q == 1:
        temp, lst[a-1] = lst[a-1], b
        idx = N+a-1

        if temp == 0:
            tree[idx] = b
            idx //= 2
            while idx != 1:
                tree[idx] = tree[idx*2] * tree[idx*2+1]
                tree[idx] %= mod
                idx //= 2
        else:
            while idx != 1:
                tree[idx] *= pow(temp, -1, mod)
                tree[idx] *= b
                tree[idx] %= mod
                idx //= 2
    elif q == 2:
        a += N-1
        b += N
        ans = 1
        while a < b:
            if a % 2:
                ans *= tree[a]
                ans %= mod
                a += 1
            if b % 2:
                ans *= tree[b-1]
                ans %= mod
                b -= 1
            a //= 2
            b //= 2
        print(ans)
