import sys
input = sys.stdin.readline

N = int(input())
bitN = 2**N
human = []
for i in range(N):
    human.append([*map(int, input().split())])

dp = [[0]*(bitN) for i in range(N)]
for i in range(N):
    dp[0][1<<i] = human[0][i]
for i in range(1, N):
    for j in range(N):
        bit = 1<<j
        for k in range(bitN):
            if not dp[i-1][k]:
                continue
            if k&bit:
                continue
            if not dp[i][k+bit]:
                dp[i][k+bit] = dp[i-1][k] + human[i][j]
                continue
            dp[i][k+bit] = min(dp[i][k+bit], dp[i-1][k] + human[i][j])

print(dp[N-1][bitN-1])