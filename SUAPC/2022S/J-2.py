import sys
input = sys.stdin.readline

N = int(input())
lst = []
compset = set()
for i in range(N):
    l, r, v = map(int, input().split())
    compset.add(l)
    compset.add(r)
    lst.append([l, r, v])

complst = list(compset)
complst.sort()
compdct = dict()
for i in range(len(complst)):
    compdct[complst[i]] = i

for i in range(N):
    for j in range(2):
        lst[i][j] = compdct[lst[i][j]]

tree = [0] * (4*N)


def update(idx, v):
    idx += 2*N
    while idx:
        tree[idx] += v
        idx //= 2


def query(a, b):
    temp = 0
    a += 2*N
    b += 2*N+1
    while a < b:
        if a % 2:
            temp += tree[a]
            a += 1
        if b % 2:
            b -= 1
            temp += tree[b]
        a //= 2
        b //= 2
    return temp


lst.sort(key=lambda x: (x[1], -x[0]))
# print(lst)

ans = 0

for i in range(N):
    curstart, curend, value = lst[i]
    update(curstart, value)
    ans = max(ans, query(curstart, curend))

print(ans)
