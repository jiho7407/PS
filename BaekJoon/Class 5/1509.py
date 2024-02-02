import sys

cmd = list(sys.stdin.readline().rstrip())

N = len(cmd)

dp = [[0 for i in range(N)]for j in range(N)]

for i in range(N):
    dp[i][i] = 1

for i in range(N-1):
    if cmd[i] == cmd[i+1]:
        dp[i][i+1] = 1

for s in range(N-3, -1, -1):
    for e in range(s+2, N):
        if dp[s+1][e-1] == 0:
            continue
        if cmd[s] == cmd[e]:
            dp[s][e] = 1

ansdp = [0]
for i in range(N):
    temp = 10000
    for j in range(i+1):
        if dp[j][i] == 0:
            continue
        temp = min(temp, ansdp[j] + 1)
    ansdp.append(temp)
print(ansdp[N])
