import sys

input = sys.stdin.readline

mod = 1000000007

N = int(input())
links = [[] for i in range(N)]
for i in range(N - 1):
    s, e = map(int, input().split())
    links[s].append(e)
    links[e].append(s)

DP = [
    [0, 0, 1] for i in range(N)
]  # DP[노드][자신 포함한 서브트리 크기 합, 자신 뺀 서브트리 크기 합, 자신 포함 서브트리 개수]


def dfs(cur, par):
    Osum = 0
    Xsum = 0
    cnt = 1
    for goal in links[cur]:
        if goal == par:
            continue
        dfs(goal, cur)
        Osum += DP[goal][0]
        Xsum += DP[goal][1]
        cnt *= DP[goal][2] + 1

    DP[cur][0] = cnt
    DP[cur][1] = Osum + Xsum
    DP[cur][2] = cnt

    for goal in links[cur]:
        if goal == par:
            continue
        DP[cur][0] += DP[goal][0] * cnt * pow(DP[goal][2] + 1, -1, mod) % mod

    DP[cur][0] %= mod
    DP[cur][1] %= mod
    DP[cur][2] %= mod


dfs(0, -1)
print(sum(DP[0][0:2]))

for i in range(N):
    print(DP[i])
