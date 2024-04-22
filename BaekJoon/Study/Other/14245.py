import sys
import math
input = sys.stdin.readline

def query(qs, qe, n, s, e):
    if qe < s or qs > e:
        return 0
    if qs <= s and e <= qe:
        return tree[n]
    m = (s+e)//2
    left_q = query(qs, qe, 2*n, s, m)
    right_q = query(qs, qe, 2*n+1, m+1, e)
    return left_q ^ right_q


N = int(input())
lst = [0] + [*map(int, input().split())]

mncnt = 2**(math.ceil(math.log2(N+1)))

tree = [0] * (2*mncnt)
tree[mncnt] = lst[0]

for i in range(N):
    tree[mncnt+i] = lst[i+1]^lst[i]

for i in range(mncnt-1, 0, -1):
    tree[i] = tree[2*i]^tree[2*i+1]

for Q in range(int(input())):
    q, *cmd = map(int, input().split())

    if q == 1:
        a, b, c = cmd

        aidx = mncnt + a
        while aidx:
            tree[aidx] ^= c
            aidx //= 2

        bidx = mncnt + b + 1
        while bidx:
            tree[bidx] ^= c
            bidx //= 2
    else:
        a = cmd[0]
        print(query(0, a, 1, 0, mncnt-1))

