from math import gcd

N = int(input())
S = input().split()
P = input().split()

pi = [0]*N
j = 0
for i in range(1, N):
    while j>0 and (P[i] != P[j]):
        j = pi[j-1]
    if P[i] == P[j]:
        j += 1
        pi[i] = j

S += S[:-1]

j = 0
ans = 0
for i in range(2*N-1):  
    while j>0 and (S[i] != P[j]):
        j = pi[j-1]
    if S[i] == P[j]:
        if j == N-1:
            ans += 1
            j = pi[j]
        else:
            j += 1

g = gcd(ans, N)
print(f"{ans//g}/{N//g}")