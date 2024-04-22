import sys
input = sys.stdin.readline

N = int(input())
K = int(input())
dct = dict()
where = [set() for i in range(N//2)]
opened = [False] * (N//2)
idx = 0
for i in range(K):
    c1, c2, p1, p2 = map(str, input().split())
    c1 = int(c1)
    c2 = int(c2)
    if p1 not in dct:
        dct[p1] = idx
        idx += 1
    if p2 not in dct:
        dct[p2] = idx
        idx += 1
    where[dct[p1]].add(c1)
    where[dct[p2]].add(c2)
    if p1 == p2:
        opened[dct[p1]] = True

cnts = [0, 0, 0]
for i in range(N//2):
    cnts[len(where[i])] += 1

if cnts[0] == 1 and cnts[1] == 0:
    print(1 + cnts[2] - opened.count(True))
elif cnts[0] == 0 and cnts[1] > 0:
    print(N//2 - opened.count(True))
else:
    print(cnts[2] - opened.count(True))
