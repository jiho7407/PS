import sys
import math
input = sys.stdin.readline

def update(i: int, x: int, n: int, s: int, e: int):
    if e < i or i < s :
        return tree[n]
    if i <= s and e <= i:
        tree[n] = x
        return tree[n]
    m = (s+e)//2
    update_l = update(i, x, 2*n, s, m)
    update_r = update(i, x, 2*n+1, m+1, e)
    tree[n] = min(update_l, update_r)
    return tree[n]

def query(qs: int, qe: int, n: int, s: int, e: int):
    if qe < s or e < qs :
        return inf
    if qs <= s and e <= qe:
        return tree[n]
    m = (s+e)//2
    query_l = query(qs, qe, 2*n, s, m)
    query_r = query(qs, qe, 2*n+1, m+1, e)
    mn = min(query_l, query_r)
    return mn

inf = int(1e10)
N = int(input())
mnpow = 2**(math.ceil(math.log2(N)))
mxpow = mnpow*2
tree = [inf] * mxpow
lst = [*map(int, input().split())]
for i in range(N):
    tree[mnpow+i] = lst[i]
for i in range(mnpow-1, 0, -1):
    tree[i] = min(tree[2*i], tree[2*i+1])

for M in range(int(input())):
    cmd, i, j = map(int, input().split())
    if cmd == 1:
        update(i-1, j, 1, 0, mnpow-1)
    else:
        print(query(i-1, j-1, 1, 0, mnpow-1))