import sys

input = sys.stdin.readline

N, M = map(int, input().split())
stk = [*map(int, input().split())]
stk.sort()

cursum = 0

for i in range(M):
    T, Q = map(int, input().split())
    while cursum < Q:
        if len(stk) == 0:
            print(-1)
            sys.exit()
        cursum += T
        cursum += stk.pop()
while stk:
    cursum += T + stk.pop()

print(cursum)
