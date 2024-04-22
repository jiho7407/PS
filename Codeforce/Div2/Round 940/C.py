import sys
input = sys.stdin.readline

mod = int(1e9)+7
mxN = 3*int(1e5)+100

DP = [1, 1, 3]
for i in range(3, mxN):
    DP.append(DP[-1] + 2*(i-1)*DP[-2])
    DP[-1] %= mod

for TC in range(int(input())):
    n, m = map(int, input().split())
    for i in range(m):
        a, b = map(int, input().split())
        if a == b:
            n -= 1
        else:
            n -= 2
    print(DP[n])
