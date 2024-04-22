import sys
input = sys.stdin.readline


def dist(A, B):
    return abs(A[0] - B[0]) + abs(A[1] - B[1])


N = int(input())
W = int(input())

crimes = []
for i in range(W):
    crimes.append([*map(int, input().split())])

lst1 = [[1, 1]] + crimes
lst2 = [[N, N]] + crimes

dp = [[0 for i in range(W+1)] for j in range(W+1)]

for i in range(1, W+1):
    dp[i][0] = dp[i-1][0] + dist(lst1[i-1], lst1[i])
    dp[0][i] = dp[0][i-1] + dist(lst2[i-1], lst2[i])

for i in range(1, W+1):
    for j in range(1, i-1):
        dp[i][j] = dp[i-1][j] + dist(lst1[i-1], lst1[i])
        dp[j][i] = dp[j][i-1] + dist(lst2[i-1], lst2[i])

    if i == 1:
        continue

    mn1 = int(1e10)
    mn2 = int(1e10)
    for j in range(i-1):
        mn1 = min(mn1, dp[j][i-1] + dist(lst1[j], lst1[i]))
        mn2 = min(mn2, dp[i-1][j] + dist(lst2[j], lst2[i]))
    dp[i][i-1] = mn1
    dp[i-1][i] = mn2

mn = int(1e10)
botidx = -1
sideidx = -1
for i in range(W):
    bot = dp[W][i]
    if bot < mn:
        mn = bot
        botidx = i
        sideidx = -1
    side = dp[i][W]
    if side < mn:
        mn = side
        botidx = -1
        sideidx = i

if botidx == -1:
    cur = [sideidx, W]
else:
    cur = [W, botidx]

print(mn)
ans = []

x, y = cur
while True:
    if x + y == 1:
        if x == 1:
            ans.append(1)
        else:
            ans.append(2)
        break

    if x+1 == y:
        ans.append(2)
        for i in range(y-1):
            if dp[x][i] + dist(lst2[i], lst2[y]) == dp[x][y]:
                y = i
                break
        continue

    if y+1 == x:
        ans.append(1)
        for i in range(x-1):
            if dp[i][y] + dist(lst1[i], lst1[x]) == dp[x][y]:
                x = i
                break
        continue

    if x < y:
        ans.append(2)
        y -= 1
        continue
    if y < x:
        ans.append(1)
        x -= 1
        continue

for i in range(len(ans)-1, -1, -1):
    print(ans[i])
