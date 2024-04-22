import sys
import heapq

input = sys.stdin.readline

month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
presum = [0]
for i in range(12):
    presum.append(presum[-1] + month[i])

N = int(input())
lst = []
for i in range(N):
    a, b, c, d = map(int, input().split())
    lst.append((presum[a - 1] + b, presum[c - 1] + d))

S, E = presum[2] + 1, presum[11]
lst.sort(key=lambda x: (x[0], x[1]))

today = S
ans = 0

idx = 0
mx = 0
while idx < N and today <= E:
    while idx < N and lst[idx][0] <= today:
        mx = max(mx, lst[idx][1])
        idx += 1
    if mx <= today:
        print(0)
        sys.exit()
    today = mx
    ans += 1
if today <= E:
    print(0)
else:
    print(ans)
