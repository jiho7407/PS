import sys
import math
input = sys.stdin.readline
mod = int(1e9)+7

N, Q = map(int, input().split())
mncnt = 2**(math.ceil(math.log2(N+1)))
mxcnt = mncnt*2

tree = [[1, 0] for i in range(mxcnt)]

for i in range(N):
    cmd, num = input().split()
    if cmd == "+":
        tree[mncnt+i+1] = [1, int(num)]
    else:
        tree[mncnt+i+1] = [int(num), 0]

for i in range(mncnt-1, 0, -1):
    tree[i] = [tree[2*i][0] * tree[2*i+1][0], tree[2*i][1]*tree[2*i+1][0] + tree[2*i+1][1]]
    tree[i][0] %= mod
    tree[i][1] %= mod

for q in range(Q):
    idx, cmd, num = input().split()
    idx = int(idx)
    num = int(num)

    idx += mncnt
    
    if cmd == "+":
        tree[idx] = [1, num]
    else:
        tree[idx] = [num, 0]
    idx //= 2

    while idx:
        tree[idx] = [tree[2*idx][0] * tree[2*idx+1][0], tree[2*idx][1]*tree[2*idx+1][0] + tree[2*idx+1][1]]
        tree[idx][0] %= mod
        tree[idx][1] %= mod
        idx //= 2
    
    print(tree[1][1])