import sys
import math
input = sys.stdin.readline

PI = 3.1415926535897932

for TC in range(int(input())):
    a, b, k = map(int, input().split())
    c = math.sqrt(a*a + b*b)
    R = (a+b-c)/2
    if k == 1:
        print(PI*R*R)
        continue
    lens = [R, b-R, a-R]
    ratios = []
    for i in range(3):
        cl = lens[i]
        ratios.append((math.sqrt(R*R + cl*cl)-R)/(math.sqrt(R*R + cl*cl)+R))
    rads = []
    for i in range(3):
        rads.append(R*ratios[i])
    for i in range(2, k):
        mx = max(rads)
        if mx == rads[0]:
            rads[0] *= ratios[0]
        elif mx == rads[1]:
            rads[1] *= ratios[1]
        else:
            rads[2] *= ratios[2]
    mx = max(rads)
    print(PI*mx*mx)
