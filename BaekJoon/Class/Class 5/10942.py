import sys

input = sys.stdin.readline

N = int(input())
lst = [*map(int, input().split())]

dp = [[0 for j in range(N)] for i in range(N)]

for i in range(N):
    dp[i][i] = 1
for i in range(N - 2, -1, -1):
    for j in range(i, N):
        if i == j - 1 and lst[i] == lst[j]:
            dp[i][j] = 1
        elif lst[i] == lst[j] and dp[i + 1][j - 1] == 1:
            dp[i][j] = 1
M = int(input())
for i in range(M):
    s, e = map(int, input().split())
    print(dp[s - 1][e - 1])
# for i in range(N):
#     print(*dp[i])
# dp 검사용
