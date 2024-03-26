import sys
input = sys.stdin.readline
sys.setrecursionlimit(200000)


def dfs(a, par, size):
    global comp
    curdeg = 1
    for g in links[a]:
        if g == par:
            continue
        result = dfs(g, a, size)
        if result >= size:
            comp += 1
        else:
            curdeg += result
    return curdeg


for TC in range(int(input())):
    N, K = map(int, input().split())
    links = [[] for i in range(N)]
    for i in range(N-1):
        s, e = map(int, input().split())
        links[s-1].append(e-1)
        links[e-1].append(s-1)

    left, right = 1, N
    ans = 1
    while (left <= right):
        mid = (left+right)//2

        comp = 0
        result = dfs(0, -1, mid)
        if result >= mid:
            comp += 1
        if comp > K:
            ans = mid
            left = mid+1
        else:
            right = mid-1
    print(ans)
