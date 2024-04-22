mod = 1000000000

# dp[숫자길이][최근숫자][방문여부] = 개수
dp = [[[0 for check in range(1024)] for prenum in range(10)]
      for length in range(101)]
pows = [1, 2, 4, 8, 16, 32, 64, 128, 256, 512]


def used(a, n):
    temp = a >> n
    return temp % 2


# 초기값
for i in range(1, 10):
    dp[1][i][2**i] = 1

for i in range(1, 100):
    for j in range(10):
        for k in range(1024):
            if dp[i][j][k] == 0:
                continue
            if j == 0:
                if used(k, 1):
                    dp[i+1][1][k] += dp[i][0][k]
                else:
                    dp[i+1][1][k+2] += dp[i][0][k]
            elif j == 9:
                if used(k, 8):
                    dp[i+1][8][k] += dp[i][9][k]
                else:
                    dp[i+1][8][k+256] += dp[i][9][k]
            else:
                if used(k, j-1):
                    dp[i+1][j-1][k] += dp[i][j][k]
                else:
                    dp[i+1][j-1][k+pows[j-1]] += dp[i][j][k]
                if used(k, j+1):
                    dp[i+1][j+1][k] += dp[i][j][k]
                else:
                    dp[i+1][j+1][k+pows[j+1]] += dp[i][j][k]


# 테스트
N = int(input())
ans = 0
for i in range(10):
    ans += dp[N][i][1023]
print(ans % mod)
