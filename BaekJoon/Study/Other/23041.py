from math import gcd

N, M = map(int, input().split())

def solve(a, b):
    while True:
        if a+b<=2:
            return a+b
        if a>b:
            a,b =b, a
        if b < 2*a:
            b = 2*a - b
        else:
            b %= 2*a

g = gcd(N, M)
print(g*g*solve(N//g, M//g))