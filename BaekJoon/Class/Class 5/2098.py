N = int(input())
INF = 1e10

lst = []
for i in range(N):
    lst.append([*map(int, input().split())])

dp = [[-1 for i in range(1 << N)] for j in range(N)]


def dfs(cur, visited):
    if visited == (1 << N) - 1:
        if lst[cur][0]:
            return lst[cur][0]
        else:
            return INF

    if dp[cur][visited] != -1:
        return dp[cur][visited]

    temp = INF
    for i in range(1, N):
        if lst[cur][i] == 0 or visited & (1 << i):
            continue
        temp = min(temp, dfs(i, visited | (1 << i)) + lst[cur][i])
    dp[cur][visited] = temp
    return dp[cur][visited]


print(dfs(0, 1))
