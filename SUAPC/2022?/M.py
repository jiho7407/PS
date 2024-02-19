import sys
input = sys.stdin.readline

mod = int(1e9)+7
N = int(input())

fact = [1]
for i in range(1, 600001):
    fact.append(fact[-1]*i % mod)

ans = 1
for i in range(N):
    A, B = map(int, input().split())
    ans *= fact[A+B]*pow(fact[A], -1, mod)*pow(fact[B], -1, mod) % mod - 1
    ans %= mod
print(ans)
