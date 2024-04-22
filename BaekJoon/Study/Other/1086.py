import sys
import math
input = sys.stdin.readline

N = int(input())
lst = [int(input()) for i in range(N)]
K = int(input())
lenlst = []
for i in range(N):
    lenlst.append(len(str(lst[i])))
    lst[i] %= K
modlst = [0]
temp = 1
for i in range(1, 53):
    temp *= 10
    temp %= K
    modlst.append(temp)


# dp[현재까지 쓴 숫자 비트마스킹][현재 나머지]
dp = [[0] * K for i in range(1 << N)]
dp[0][0] = 1

for i in range(1 << N):
    for j in range(N):
        if i & (1 << j):
            continue
        for k in range(K):
            dp[i | (1 << j)][(k*modlst[lenlst[j]]+lst[j]) % K] += dp[i][k]

cnt = dp[(1 << N)-1][0]
fac = sum(dp[(1 << N)-1])
g = math.gcd(cnt, fac)
print(f"{cnt//g}/{fac//g}")
