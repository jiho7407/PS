import sys
input = sys.stdin.readline

N = int(input())
lst = []
for i in range(N):
    lst.append(int(input()))
lst.sort()
cnt = [*map(int, input().split())]

tree = [0] * (2*N)
for i in range(N):
    tree[N+i] = 1
for i in range(N-1, 0, -1):
    tree[i] = tree[2*i] + tree[2*i+1]


def get(r):
    l = N
    r = N+r+1
    temp = 0
    while l < r:
        if l % 2:
            temp += tree[l]
            l += 1
        if r % 2:
            r -= 1
            temp += tree[r]
        l //= 2
        r //= 2
    return temp


def update(idx):
    idx += N
    while idx > 0:
        tree[idx] -= 1
        idx //= 2


def find(a):
    l = 0
    r = N-1
    while l <= r:
        mid = (l+r)//2
        res = get(mid)
        if res < a:
            l = mid+1
        elif res >= a:
            r = mid-1
    update(l)
    return lst[l]


ans = []
for cmd in reversed(cnt):
    ans.append(find(cmd+1))

for cmd in reversed(ans):
    print(cmd)
