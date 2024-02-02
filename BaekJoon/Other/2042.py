import sys
input = sys.stdin.readline


N, M, K = map(int, input().split())

tree = [0 for i in range(4*N)]
lst = []
for i in range(N):
    lst.append(int(input()))


def segTree(idx, start, end):
    if start == end:
        tree[idx] = lst[start]
        return tree[idx]

    mid = (start + end)//2
    left = segTree(idx*2, start, mid)
    right = segTree(idx*2+1, mid+1, end)
    tree[idx] = left + right
    return tree[idx]


def update(start, end, curidx, idx, value):
    tree[curidx] += value
    if start == end:
        return
    mid = (start + end)//2
    if idx <= mid:
        update(start, mid, curidx*2, idx, value)
    else:
        update(mid+1, end, curidx*2+1, idx, value)


def calc(sumstart, sumend, curidx, leftidx, rightidx):
    if sumstart > rightidx or sumend < leftidx:
        return 0
    if sumstart <= leftidx and rightidx <= sumend:
        return tree[curidx]
    mid = (leftidx + rightidx)//2
    return calc(sumstart, sumend, curidx*2, leftidx, mid) + calc(sumstart, sumend, curidx*2+1, mid+1, rightidx)


segTree(1, 0, N-1)

for i in range(M+K):
    a, b, c = map(int, input().split())
    if a == 1:
        update(0, N-1, 1, b-1, c-lst[b-1])
        lst[b-1] = c
    else:
        print(calc(b-1, c-1, 1, 0, N-1))
