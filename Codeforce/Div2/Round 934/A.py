import sys
input = sys.stdin.readline

for TC in range(int(input())):
    N, K = map(int, input().split())
    if (K >= N-1):
        print(1)
    else:
        print(N)
