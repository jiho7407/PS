import sys
sys.setrecursionlimit(int(1e5)+100)
input = sys.stdin.readline

V, E = map(int, input().split())

links = [[] for i in range(V+1)]
for i in range(E):
    s, e = map(int, input().split())
    links[s].append(e)
    
pa = [-1]*(V+1)
stk = []
fin = [False]*(V+1)
cnt = 0

scclst = []

def dfs(a):
    global cnt # 몬가 오일러회로 느낌이네
    cnt += 1
    pa[a] = cnt
    stk.append(a)

    result = pa[a]
    for goal in links[a]:
        if pa[goal] == -1:
            result = min(result, dfs(goal))
        elif not fin[goal]:
            result = min(result, pa[goal])
    
    if result == pa[a]:
        scc = []
        while True:
            top = stk.pop()
            scc.append(top)
            fin[top] = True
            if top == a:
                break
        scc.sort()
        scclst.append(scc)
    return result

for i in range(1, V+1):
    if pa[i] == -1:
        dfs(i)

scclst.sort()
print(len(scclst))
for i in range(len(scclst)):
    print(*scclst[i], end=" ")
    print(-1)