import sys
input = sys.stdin.readline

inf = 10**11
N = int(input())
lst = []
for i in range(N):
    lst.append([*map(int,input().split())])
dp = [[0 for i in range(N)] for j in range(N)]

k = 1
for dist in range(1, N):
    for row in range(N-dist):
        temp = inf
        for _ in range(dist):
            temp = min(temp,
                       dp[row][row+_] +dp[row+_+1][row+dist] + lst[row][0]*lst[row+_][1]*lst[row+dist][1])
        dp[row][row+dist] = temp

print(dp[0][N-1])

# #테스트
# print(lst)
# for i in range(N):
#     print(*dp[i])