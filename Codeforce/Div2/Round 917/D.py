import sys
import math
import bisect
input = sys.stdin.readline

for TC in range(int(input())):
    n, k = map(int, input().split())
    plst = [*map(int, input().split())]
    qlst = [*map(int, input().split())]
    cnt = 0

    for i in range(k-1):
        for j in range(1, k):
            if qlst[i] > qlst[j]:
                cnt += n
    qlst.sort()

    for i in range(n-1):
        for j in range(i+1, n):
            for _ in range(k):
                # print(qlst, math.log2(plst[i]/plst[j]+_))
                cnt += bisect.bisect_left(qlst, math.log2(plst[i]/plst[j]+_))
    print(cnt)
