import sys
import math
input = sys.stdin.readline

N = int(input())
lst = [0] + [*map(int, input().split())]

halfcnt = 2**(math.ceil(math.log2(N+1))-1)
mxcnt = halfcnt * 2

otree = [0] * mxcnt
etree = [0] * mxcnt

for i in range((N+1)//2):
    otree[halfcnt+i] = lst[2*i] ^ lst[2*i+1]

for i in range(N//2):
    etree[halfcnt+i] = lst[2*i+1] ^ lst[2*i+2]

for i in range(halfcnt-1, 0, -1):
    otree[i] = otree[2*i] ^ otree[2*i+1]
    etree[i] = etree[2*i] ^ etree[2*i+1]

def query(tree, a, n, s, e):
    qs, qe = 0, a
    if qe<s or e < qs:
        return 0
    if qs<=s and e<=qe:
        return tree[n]
    m = (s+e)//2
    lq = query(tree, a, 2*n, s, m)
    rq = query(tree, a, 2*n+1, m+1, e)
    return lq^rq

def solve(a, b):
    if a == 0:
        aq = 0
    elif a%2:
        aq = query(otree, a//2, 1, 0, halfcnt-1)
    else:
        aq = query(etree, a//2 - 1, 1, 0, halfcnt-1)
    
    if b == 0:
        bq = 0
    elif b%2:
        bq = query(otree, b//2, 1, 0, halfcnt-1)
    else:
        bq = query(etree, b//2 - 1, 1, 0, halfcnt-1)
    return aq^bq

def update(tree, a, k):
    idx = halfcnt + a
    while idx:
        tree[idx] ^= k
        idx //= 2

def update2(a, b, k):
    a += 1
    b += 1
    if a%2:
        update(otree, a//2, k)
    else:
        update(etree, a//2-1, k)

    if b%2:
        update(otree, b//2, k)
    else:
        update(etree, b//2-1, k)
    
for Q in range(int(input())):
    q, *cmd = map(int, input().split())
    if q == 1:
        a, b, k = cmd
        update2(a, b+1, k)
    
    else:
        a, b = cmd
        print(solve(a, b+1))