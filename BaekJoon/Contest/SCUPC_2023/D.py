import sys
from itertools import combinations
input = sys.stdin.readline

N, M = map(int, input().split())
modelnum = [i for i in range(N)]
answer = [*map(int, input().split())]
models = []
for i in range(N):
    models.append([*map(int, input().split())])


def score(scorelst):
    tempscore = 0
    for i in range(M):
        if scorelst[i] == answer[i]:
            tempscore += 1
    return tempscore


def hardboat(hbtuple):
    anstk = []
    for i in range(M):
        temp = 0
        for mn in hbtuple:
            if models[mn][i] == 1:
                temp += 1
        if temp > len(hbtuple)//2:
            anstk.append(1)
        else:
            anstk.append(0)
    return score(anstk)


single = 0
for i in range(N):
    single = max(single, score(models[i]))

mx = 0
for i in range(3, N+1, 2):
    combination = list(combinations(modelnum, i))
    for comb in combination:
        mx = max(mx, hardboat(comb))

if mx > single:
    print(1)
else:
    print(0)
