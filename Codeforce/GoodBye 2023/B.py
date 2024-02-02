import sys
import math
input = sys.stdin.readline

for TC in range(int(input())):
    N, M = map(int, input().split())
    x = math.lcm(N, M)
    if (M/N).is_integer():
        x *= (M//N)
    print(x)
