mx = int(1e7)+1

mu = [0] * mx
mu[1] = 1
for i in range(1, mx):
    for j in range(2*i, mx, i):
        mu[j] -= mu[i]

a, b, c, d = map(int, input().split())

def solve(N, M):
    temp = 0
    for d in range(1, min(N, M)+1):
        temp += mu[d] * (N//d) * (M//d)
    return temp

print(solve(b, d) - solve(a-1, d) - solve(c-1, b) + solve(a-1, c-1))