import sys
input = sys.stdin.readline

N = int(input())
lst = [*map(int, input().split())]

mod = 998244353
ans = 0
pfsum = 0


def conv(N):
    digit = len(str(N))
    return 10**(digit)


for idx, num in enumerate(lst):
    ans += (num*idx) % mod
    ans += pfsum*conv(num)
    pfsum += num
    ans %= mod

print(ans)
