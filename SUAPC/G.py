import sys
from functools import cache
input = sys.stdin.readline

N, K = map(int, input().split())
lst = [*map(int, input().split())]

mxlev = 4
treeN = 2**mxlev
tree = [0] * (treeN*2)

for i in range(N):
    tree[treeN+lst[i]] += 1
for i in range(treeN-1, 0, -1):
    tree[i] = tree[i*2] + tree[i*2+1]

cnt = [0, 0, 0]


@cache
def solveAND(s, k, lev, curnode):
    if lev == mxlev:
        return tree[curnode]
    if tree[curnode] == 0:
        return 0
    cmd = s[0]
    kcmd = k[0]

    if cmd == "1" and kcmd == "1":
        return solveAND(s[1:], k[1:], lev+1, curnode*2+1)
    elif cmd == "1" and kcmd == "0":
        return solveAND(s[1:], k[1:], lev+1, curnode*2)
    elif cmd == "0" and kcmd == "1":
        return 0
    elif cmd == "0" and kcmd == "0":
        return solveAND(s[1:], k[1:], lev+1, curnode*2) + solveAND(s[1:], k[1:], lev+1, curnode*2+1)


@cache
def solveOR(s, k, lev, curnode):
    if tree[curnode] == 0:
        return 0
    if lev == mxlev:
        return tree[curnode]
    cmd = s[0]
    kcmd = k[0]

    if cmd == "1" and kcmd == "1":
        return solveOR(s[1:], k[1:], lev+1, curnode*2) + solveOR(s[1:], k[1:], lev+1, curnode*2+1)
    elif cmd == "1" and kcmd == "0":
        return 0
    elif cmd == "0" and kcmd == "1":
        return solveOR(s[1:], k[1:], lev+1, curnode*2+1)
    elif cmd == "0" and kcmd == "0":
        return solveOR(s[1:], k[1:], lev+1, curnode*2)


@cache
def solveXOR(s, k, lev, curnode):
    if lev == mxlev:
        return tree[curnode]
    if tree[curnode] == 0:
        return 0
    cmd = s[0]
    kcmd = k[0]

    if cmd == "1" and kcmd == "1":
        return solveXOR(s[1:], k[1:], lev+1, curnode*2)
    elif cmd == "1" and kcmd == "0":
        return solveXOR(s[1:], k[1:], lev+1, curnode*2+1)
    elif cmd == "0" and kcmd == "1":
        return solveXOR(s[1:], k[1:], lev+1, curnode*2+1)
    elif cmd == "0" and kcmd == "0":
        return solveXOR(s[1:], k[1:], lev+1, curnode*2)


k = bin(K)[2:].zfill(mxlev)
for cmd in lst:
    s = bin(cmd)[2:].zfill(mxlev)
    cnt[0] += solveAND(s, k, 0, 1)
    cnt[1] += solveOR(s, k, 0, 1)
    cnt[2] += solveXOR(s, k, 0, 1)

    if cmd & cmd == K:
        cnt[0] -= 1
    if cmd | cmd == K:
        cnt[1] -= 1
    if cmd ^ cmd == K:
        cnt[2] -= 1
for i in range(3):
    print(cnt[i]//2, end=" ")
