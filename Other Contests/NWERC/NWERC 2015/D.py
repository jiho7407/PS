import math

N, R, P = map(int, input().split())

dp = [-1] * (N+1)
dp[0] = 0
dp[1] = 0

def solve(a):
    if dp[a] != -1:
        return dp[a]
    temp = int(1e16)
    for i in range(2, math.floor(math.sqrt(a)) + 1):
        temp = min(temp, solve((a-1)//i + 1) + R + (i-1)*P)
        temp = min(temp, solve(i) + R + ((a-1)//i)*P)
    temp = min(temp, R + (a-1)*P)
    dp[a] = temp
    return temp

print(solve(N))