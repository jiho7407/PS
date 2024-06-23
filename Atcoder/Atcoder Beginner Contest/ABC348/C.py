import sys
input = sys.stdin.readline

N = int(input())
dct = dict()
for i in range(N):
    A, C = map(int, input().split())
    if C in dct:
        dct[C] = min(dct[C], A)
    else:
        dct[C] = A
print(max(dct.values()))
