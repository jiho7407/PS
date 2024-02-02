import sys
import math
input = sys.stdin.readline

for TC in range(int(input())):
    n = int(input())
    lst = [*map(int, input().split())]
    s = sum(lst)
    if math.sqrt(s).is_integer():
        print("YES")
    else:
        print("NO")
