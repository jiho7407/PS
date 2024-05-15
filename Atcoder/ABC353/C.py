import sys
from bisect import bisect_left
input = sys.stdin.readline

N = int(input())
lst = [*map(int, input().split())]
ans = 0
mod = int(1e8)
for i in range(N):
    ans += (lst[i] % mod)*(N-1)

lst.sort()
allcnt = 0
for i in range(N):
    cnt = N-bisect_left(lst, mod - lst[i])
    if (lst[i] >= mod - lst[i]):
        cnt -= 1
    allcnt += cnt
ans -= (allcnt//2)*mod
print(ans)
