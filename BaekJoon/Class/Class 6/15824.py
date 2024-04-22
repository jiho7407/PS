import sys
input = sys.stdin.readline

mod = int(1e9)+7

N = int(input())
lst = [*map(int, input().split())]
lst.sort()

tempsum = 0
temppl = 1
ans = 0
for i in range(N):
    tempsum += lst[N-i-1] - lst[i]
    tempsum %= mod
    ans += tempsum * temppl % mod
    ans %= mod
    temppl *= 2
    temppl %= mod
print(ans)
