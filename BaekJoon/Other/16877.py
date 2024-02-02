import sys
input = sys.stdin.readline

N = int(input())
lst = [*map(int, input().split())]

mx = max(lst)

fibo = [1, 2, 3, 5]
while True:
    if fibo[-1] > mx:
        break
    fibo.append(fibo[-1] + fibo[-2])

grundy = [0, 1]


def mex(mexset):
    i = 0
    while i in mexset:
        i += 1
    return i


for i in range(2, mx+1):
    tempset = set()
    idx = 0
    while True:
        if fibo[idx] > i:
            break
        tempset.add(grundy[i - fibo[idx]])
        idx += 1
    grundy.append(mex(tempset))


def spgr(spgrlst):
    tempspgr = 0
    for i in spgrlst:
        tempspgr ^= grundy[i]
    return tempspgr


if spgr(lst) == 0:
    print('cubelover')
else:
    print('koosaga')
