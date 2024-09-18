import sys
sys.setrecursionlimit(int(1e5)+100)
input = sys.stdin.readline

N = int(input())
links = [[] for i in range(N)]
for i in range(N-1):
    s, e = map(int, input().split())
    links[s].append(e)
    links[e].append(s)
dp = [*map(int, input().split())]


def dfs(cur, par):
    for goal in links[cur]:
        if goal == par:
            continue
        dp[cur] += max(0, dfs(goal, cur))
    return dp[cur]


print(dfs(0, -1))
