import sys

input = sys.stdin.readline

mod = int(1e9) + 7

for TC in range(int(input())):
    p, c, k = map(int, input().split())
    q = mod + 1 - p
    dp = [0]
    Q = [1]

    for i in range(1, min(c, k + 1) + 1):
        Q.append(Q[-1] * q % mod)

    for i in range(1, min(c, k + 1)):
        dp.append((dp[-1] + p) % mod)

    if k >= c:
        window = 0
        for i in range(1, min(c, k + 1) + 1):
            window += ((dp[c - i] + 1) * Q[i - 1]) % mod * p % mod
            window %= mod

        for i in range(c, k + 1):
            dp.append(((dp[i - c] + 1) * Q[c] + window) % mod)
            temp = ((dp[i] + 1) - (dp[i - c] + 1) * Q[c]) % mod
            if temp < 0:
                temp += mod
            window = (window * q) + (temp * p % mod)
            window %= mod

    for i in range(1, k + 1):
        print(dp[i])
