import sys
import math
input = sys.stdin.readline

D = int(input())

ans = 1e12
for x in range(int(math.sqrt(D))+1):
    st = math.sqrt(D - x*x)
    ans = min(ans, abs(D - x*x - math.floor(st)*math.floor(st)))
    ans = min(ans, abs(D - x*x - math.ceil(st)*math.ceil(st)))
print(ans)
