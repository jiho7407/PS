import sys
from math import gcd
input = sys.stdin.readline

N = int(input())

dct = dict()

for i in range(N):
    x, y = map(int, input().split())
    g = gcd(x, y)
    px = x // g
    py = y // g
    if (px, py) in dct:
        dct[(px, py)] += 1
    else:
        dct[(px, py)] = 1

print(max(dct.values()))