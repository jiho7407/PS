import sys
import copy
input = sys.stdin.readline

N = int(input())

mx = 1000001
xseg = [0]*(2*mx)
xidx = [0]*(2*mx)
yseg = [0]*(2*mx)
yidx = [0]*(2*mx)

swallos = []
for i in range(N):
    x, y, v = map(int, input().split())
    xseg[mx+x] += v
    yseg[mx+y] += v
    swallos.append((x, y, v))

for i in range(mx, 2*mx):
    xidx[i] = i
    yidx[i] = i

for i in range(mx-1, 0, -1):
    S1 = xseg[i*2]
    S2 = xseg[i*2+1]
    if S1 > S2:
        xseg[i] = S1
        xidx[i] = xidx[i*2]
    else:
        xseg[i] = S2
        xidx[i] = xidx[i*2+1]

    S1 = yseg[i*2]
    S2 = yseg[i*2+1]
    if S1 > S2:
        yseg[i] = S1
        yidx[i] = yidx[i*2]
    else:
        yseg[i] = S2
        yidx[i] = yidx[i*2+1]

ans = 0

def solve(segtree, idxtree):
    temp = segtree[1]

    tempi = idxtree[1]
    
    i = tempi
    segtree[i] = 0
    i //= 2
    while i:
        S1 = segtree[i*2]
        S2 = segtree[i*2+1]
        if S1 > S2:
            segtree[i] = S1
            idxtree[i] = idxtree[i*2]
        else:
            segtree[i] = S2
            idxtree[i] = idxtree[i*2+1]
        i //= 2

    return temp, tempi

def update(segtree, idxtree, idx, value):
    i = idx
    segtree[i] = value
    i //= 2
    while i:
        S1 = segtree[i*2]
        S2 = segtree[i*2+1]
        if S1 > S2:
            segtree[i] = S1
            idxtree[i] = idxtree[i*2]
        else:
            segtree[i] = S2
            idxtree[i] = idxtree[i*2+1]
        i //= 2

ans = 0
# X X X
temp1, tempi1 = solve(xseg, xidx)
temp2, tempi2 = solve(xseg, xidx)
temp3, tempi3 = solve(xseg, xidx)

ans = max(ans, temp1+temp2+temp3)

update(xseg, xidx, tempi1, temp1)
update(xseg, xidx, tempi2, temp2)
update(xseg, xidx, tempi3, temp3)

print(solve(xseg, xidx))