import sys
input = sys.stdin.readline

N = int(input())

dct = dict()

def solve(a):
    if a <= 1:
        return 0
    if a in dct:
        return dct[a]
    if a%2:
        low = solve(a//2)
        high = solve(a//2 + 1)
        dct[a] = low + high + a
        return dct[a]
    else:
        low = solve(a//2)
        dct[a] = low*2 + a
        return dct[a]
    

print(solve(N))