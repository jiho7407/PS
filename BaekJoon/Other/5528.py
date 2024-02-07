import sys
input = sys.stdin.readline

N, M = map(int, input().split())
S = input().rstrip()
T = input().rstrip()

dpI = [[-10] * (M+1) for j in range(N+1)] # dp[S개수][T개수]
dpO = [[0] * (M+1) for j in range(N+1)]

for i in range(N+1):
    for j in range(M+1):
        if i < N:
            Scmd = S[i]
            if Scmd == "O":
                dpO[i+1][j] = max(dpO[i+1][j], dpI[i][j] + 1)
            else:
                dpI[i+1][j] = max(dpI[i+1][j], dpO[i][j] + 1)

        if j < M:
            Tcmd = T[j]
            if Tcmd == "O":
                dpO[i][j+1] = max(dpO[i][j+1], dpI[i][j] + 1)
            else:
                dpI[i][j+1] = max(dpI[i][j+1], dpO[i][j] + 1)

ans = 0
for i in range(N+1):
    for j in range(M+1):
        cmd = dpI[i][j]
        if cmd % 2:
            ans = max(ans, cmd)

if ans == -10:
    print(0)
else:
    print(ans)