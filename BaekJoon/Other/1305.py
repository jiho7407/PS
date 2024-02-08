N = int(input())
P = input().rstrip()

S = P * 3

pi = [0] * N
j = 0
for i in range(1, N):
    while j > 0 and (P[i] != P[j]):
        j = pi[j-1]
    if P[i] == P[j]:
        j += 1
        pi[i] += j

print(pi)
print(N - pi[N-1])