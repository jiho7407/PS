import sys
input = sys.stdin.readline
sys.setrecursionlimit(2*int(1e5)+100)

N, M = map(int, input().split())

links = [[] for i in range(2*N)]  # x1, ~x1, x2, ~x2...


def invert(a):
    if a % 2:
        return a-1
    else:
        return a+1


def makenode(a):
    if a > 0:
        return a*2-2
    else:
        a = abs(a)
        return a*2-1


for i in range(M):
    i, j = map(int, input().split())

    links[invert(makenode(i))].append(makenode(j))
    links[invert(makenode(j))].append(makenode(i))

pa = [0] * (2*N)
fin = [False] * (2*N)
scc = [0] * (2*N)
stk = []
cnt = 0
sccidx = 0


def dfs(a):
    global cnt, sccidx
    cnt += 1
    stk.append(a)
    pa[a] = cnt
    result = pa[a]

    for goal in links[a]:
        if not pa[goal]:
            result = min(result, dfs(goal))
        if not fin[goal]:
            result = min(result, pa[goal])

    if result == pa[a]:
        sccidx += 1
        while True:
            top = stk.pop()
            fin[top] = True
            scc[top] = sccidx
            if top == a:
                break
    return result


for i in range(2*N):
    if not pa[i]:
        dfs(i)

pos = True
for i in range(N):
    if scc[2*i] == scc[2*i+1]:
        pos = False
        break

if pos:
    print(1)
else:
    print(0)
