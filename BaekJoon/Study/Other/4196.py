import sys
input = sys.stdin.readline
sys.setrecursionlimit(int(1e5)+100)

def dfs(a):
    global cnt
    global sccidx
    cnt += 1
    pa[a] = cnt
    stk.append(a)

    result = pa[a]
    for goal in links[a]:
        if not pa[goal]:
            result = min(result, dfs(goal))
        elif not fin[goal]:
            result = min(result, pa[goal])
    
    if result == pa[a]:
        while True:
            top = stk.pop()
            fin[top] = True
            scc[top] = sccidx
            if top == a:
                sccidx += 1
                break
    return result



for TC in range(int(input())):
    N, M = map(int, input().split())
    links = [[] for i in range(N+1)]
    linkstore = []
    for i in range(M):
        a, b = map(int, input().split())
        links[a].append(b)
        linkstore.append((a, b))

    pa = [0 for i in range(N+1)]
    scc = [0 for i in range(N+1)]
    fin = [False for i in range(N+1)]
    stk = []
    cnt = 0
    sccidx = 1

    for i in range(1, N+1):
        if not pa[i]:
            dfs(i)
    
    sccinlink = [0] * (sccidx)
    for a, b in linkstore:
        s, e = scc[a], scc[b]
        if s == e:
            continue
        sccinlink[e] += 1

    print(sccinlink.count(0)-1)