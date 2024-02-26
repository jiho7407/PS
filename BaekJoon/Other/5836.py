S = input()
T = input()
Slen = len(S)
Tlen = len(T)

pi = [0] * Tlen
k = 0
for i in range(1, Tlen):
    while k and T[k] != T[i]:
        k = pi[k-1]
    if T[k] == T[i]:
        k += 1
    pi[i] = k

dp = [[-1] * (Tlen) for i in range(Slen+1)]
dp[0][0] = 0
for i in range(Slen):
    for j in range(Tlen):
        if dp[i][j] != -1:
            dp[i+1][j] = max(dp[i+1][j], dp[i][j])
            k = j
            while k and S[i] != T[k]:
                k = pi[k-1]
            if S[i] == T[k]:
                k += 1
            if k < Tlen:
                dp[i+1][k] = max(dp[i+1][k], dp[i][j]+1)

print(Slen - max(dp[Slen]))
