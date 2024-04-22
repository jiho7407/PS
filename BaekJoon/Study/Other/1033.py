import sys
import math
input = sys.stdin.readline

N = int(input())
links = [[] for i in range(N)]

alllcm = 1
for i in range(N-1):
    a, b, p, q = map(int, input().split())
    temp = math.gcd(p, q)
    p //= temp
    q //= temp
    links[a].append([b, p, q])
    links[b].append([a, q, p])
    alllcm *= math.lcm(p, q)


def calc(a):
    visited[a] = True
    for goal, p, q in links[a]:
        if visited[goal]:
            continue
        ans[goal] = ans[a]*q//p
        calc(goal)


visited = [False for i in range(N)]
ans = [1 for i in range(N)]
ans[0] = alllcm
calc(0)

tempgcd = ans[0]
for i in range(1, N):
    tempgcd = math.gcd(tempgcd, ans[i])
for i in range(N):
    ans[i] //= tempgcd
print(*ans)
