import sys
import math
import bisect
input = sys.stdin.readline

for TC in range(int(input())):
    N = int(input())
    lst = [*map(int, input().split())]
    lst.sort()
    idx = math.ceil(N/2)-1
    num = lst[idx]
    print(bisect.bisect_right(lst, num)-idx)
