import sys
input = sys.stdin.readline
mod = int(1e9)+7


def calcp(num):
    b = 2
    temp = (num*2) % mod
    while True:
        if temp <= b:
            return [temp, b]
        b += 1
        temp = (temp+num) % mod


def answering(x, y):
    return ((x % mod)*pow(y, -1, mod)) % mod


for TC in range(int(input())):
    p, c, N = map(int, input().split())
    percent = calcp(p)
    percent = [1, 2]

    # lst = []
    # for n in range(2, 11):
    #     lst.append(percent[1]**(n-2)*(n-1))
    # print(lst)

    dp = [[[0 for i in range(c)] for j in range(N+1)] for k in range(N+1)]
    # dp[뽑은횟수][얻은개수][연속 실패횟수]
    suc = percent[0]
    fail = percent[1]-percent[0]
    dp[0][0][0] = 1

    for i in range(N):
        for j in range(N):
            for k in range(c-1):
                dp[i+1][j+1][0] += dp[i][j][k]*suc
                dp[i+1][j][k+1] += dp[i][j][k]*fail
            dp[i+1][j+1][0] += dp[i][j][c-1]*percent[1]

    for i in range(1, N+1):
        ans = 0
        for j in range(N+1):
            ans += j * sum(dp[i][j])
        print(ans, end=', ')
        # print(i, answering(ans, percent[1]**i))
