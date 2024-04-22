import sys
input = sys.stdin.readline
sys.setrecursionlimit(int(1e6))

N = int(input())
vil = [0] + [*map(int, input().split())]
links = [[] for i in range(N+1)]

for i in range(N-1):
    s, e = map(int, input().split())
    links[s].append(e)
    links[e].append(s)

tree = [[] for i in range(N+1)]
visited = [False for i in range(N+1)]


def maketree(cur):
    for goal in links[cur]:
        if visited[goal]:
            continue
        tree[cur].append(goal)
        visited[goal] = True
        maketree(goal)


visited[1] = True
maketree(1)

dp = [[0, 0] for i in range(N+1)]  # dp[현재노드][우수마을 선정여부] = 최대


def solve(cur, wasgreat):
    global dp
    if wasgreat:
        if dp[cur][0]:
            return dp[cur][0]
        temp = 0
        for goal in tree[cur]:
            temp += solve(goal, 0)
        dp[cur][0] = temp
        return temp
    else:

        if dp[cur][0]:
            mx1 = dp[cur][0]
        else:
            temp = 0
            for goal in tree[cur]:
                temp += solve(goal, 0)
            dp[cur][0] = temp
            mx1 = temp

        if dp[cur][1]:
            mx2 = dp[cur][1]
        else:
            temp = vil[cur]
            for goal in tree[cur]:
                temp += solve(goal, 1)
            dp[cur][1] = temp
            mx2 = temp

        return max(mx1, mx2)


solve(1, False)
solve(1, True)
# print(dp)
print(max(dp[1]))
