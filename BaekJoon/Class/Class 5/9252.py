import sys
input = sys.stdin.readline

stra = input().rstrip()
strb = input().rstrip()

alen = len(stra)
blen = len(strb)
dp = [[0 for i in range(alen)] for j in range(blen)]

if stra[0] == strb[0]:
    dp[0][0] = 1

for i in range(1, alen):
    if dp[0][i-1] == 1:
        dp[0][i] = 1
    elif strb[0] == stra[i]:
        dp[0][i] = 1

for i in range(1, blen):
    if dp[i-1][0] == 1:
        dp[i][0] = 1
    elif stra[0] == strb[i]:
        dp[i][0] = 1


for i in range(1, blen):
    for j in range(1, alen):
        if stra[j] == strb[i]:
            dp[i][j] = max(dp[i][j-1], dp[i-1][j-1]+1)
        else:
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])

ans = dp[blen-1][alen-1]
print(ans)
x = blen-1
y = alen-1
stk = []
while (ans > 0):
    while (y > 0):
        if dp[x][y-1] <= ans-1:
            break
        y -= 1
    while (x > 0):
        if dp[x-1][y] <= ans-1:
            break
        x -= 1
    stk.append(strb[x])
    x -= 1
    y -= 1
    ans -= 1
stk.reverse()
print(''.join(map(str, stk)))
