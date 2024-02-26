S = input()
T = input()
Slen = len(S)
Tlen = len(T)

dp = [0] * Slen

pi = [0] * Tlen
k = 0
for i in range(1, Tlen):
    while k and T[k] != T[i]:
        k = pi[k-1]
    if T[k] == T[i]:
        k += 1
    pi[i] = k

k = 0
lst = []
for i in range(Slen):
    lst.append(i)
    while k and S[i] != T[k]:
        k = pi[k-1]
    if S[i] == T[k]:
        k += 1
    if k == Tlen:
        for _ in range(Tlen):
            dp[lst.pop()] = 0
        if lst:
            k = dp[lst[-1]]
        else:
            k = 0
    else:
        dp[i] = k

for ans in lst:
    print(S[ans], end="")
