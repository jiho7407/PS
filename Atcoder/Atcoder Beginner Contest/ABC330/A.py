import sys
input = sys.stdin.readline

N, M = map(int, input().split())
lst = [*map(int, input().split())]
ans = 0
for i in range(N):
    if lst[i] >= M:
        ans += 1
print(ans)
