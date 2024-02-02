N = input().rstrip()

size = len(N)
ans = 0

for S in range(1, 9*size + 1):
    dp = [[[[0 for i in range(2)] for j in range(S)]
           for k in range(S+1)] for m in range(size+1)]
    dp[0][0][0][1] = 1
    for i in range(size):
        for j in range(S+1):
            for k in range(S):
                for m in range(2):
                    cmd = dp[i][j][k][m]
                    if cmd == 0:
                        continue
                    for d in range(10):
                        if j+d > S:
                            continue
                        if m and int(N[i]) < d:
                            continue
                        dp[i+1][j+d][(k*10+d) % S][m and int(N[i]) == d] += cmd
    ans += sum(dp[size][S][0])
print(ans)
