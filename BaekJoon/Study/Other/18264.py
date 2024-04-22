import sys
input = sys.stdin.readline

N, M, K = map(int, input().split())
S = input().rstrip()
A = []
for i in range(M):
    A.append([*map(int, input().split())])

for k in range(M):
    for i in range(M):
        for j in range(M):
            cmd = A[i][k] + A[k][j]
            if cmd < A[i][j]:
                A[i][j] = cmd

dp = [[-1] * M for i in range(N)]

for i in range(M):
    cmd = S[0]
    dp[0][i] = A[ord(cmd)-97][i]

pfsum = [[0] for i in range(M)]
for i in range(M):
    for j in range(N):
        pfsum[i].append(pfsum[i][-1] + A[ord(S[j])-97][i])

if 2*K <= N:
    for i in range(1, 2*K-1):
        cmd = S[i]
        for j in range(M):
            dp[i][j] = dp[i-1][j] + A[ord(cmd)-97][j]

    for i in range(2*K-1, N):
        cmd = S[i]
        for j in range(M):
            dp[i][j] = min(min(dp[i-K]) + pfsum[j][i+1] - pfsum[j][i-K+1], dp[i-1][j]+A[ord(cmd)-97][j])
else:
    for i in range(M):
        dp[N-1][i] = pfsum[i][-1]

print(min(dp[N-1]))