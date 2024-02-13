import sys
import heapq
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

n = len(complst)
tree = [0] * (2*n)


def update(idx, v):
    idx += n
    while idx:
        tree[idx] += v
        idx //= 2


def query(a, b):
    temp = 0
    a += n
    b += n+1
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


pq = []
ans = 0

for i in range(N):
    curstart, curend, value = lst[i]
    curstart = compdct[curstart]
    curend = compdct[curend]

    while pq and pq[0][0] < curstart:
        pend, pstart, pvalue = heapq.heappop(pq)
        update(-pstart, pvalue)
        ans = max(ans, query(-pstart, pend))

    heapq.heappush(pq, (curend, -curstart, value))

while pq:
    pend, pstart, pvalue = heapq.heappop(pq)
    update(-pstart, pvalue)
    ans = max(ans, query(-pstart, pend))

print(ans)
