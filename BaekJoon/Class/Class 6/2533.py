import sys
sys.setrecursionlimit(int(1e6))
input = sys.stdin.readline

N = int(input())
link = [[] for i in range(N+1)]
for i in range(N-1):
    a, b = map(int, input().split())
    link[a].append(b)
    link[b].append(a)

visited = [False for i in range(N+1)]
dp = [[0, 1] for i in range(N+1)]  # False, True


def solve(s):
    if visited[s]:
        return
    visited[s] = True
    for e in link[s]:
        if visited[e]:
            continue
        solve(e)
        dp[s][0] += dp[e][1]
        dp[s][1] += min(dp[e][0], dp[e][1])


solve(1)
print(min(dp[1]))
