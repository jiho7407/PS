import sys
import copy
input = sys.stdin.readline

K = int(input())
T1 = [*map(int, input().split())]
T2 = [*map(int, input().split())]

def solve(s, e, cs, ce):
    if s == e:
        if T2[cs] == T1[s]:
            return 1
        else:
            return 0
        
    m = (s+e)//2
    cm = (cs+ce)//2

    # 뒤집지 않은 경우
    nonflip = solve(s, m, cs, cm) + solve(m+1, e, cm+1, ce)

    # 뒤집은 경우
    flip = solve(s, m, cm+1, ce) + solve(m+1, e, cs, cm)

    return max(nonflip, flip)

mx = 2**(K-1)-1
print(solve(0, mx, 0, mx))