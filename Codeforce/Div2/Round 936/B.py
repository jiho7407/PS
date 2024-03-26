import sys
input = sys.stdin.readline

mod = int(1e9) + 7

for TC in range(int(input())):
    N, K = map(int, input().split())
    lst = [*map(int, input().split())]
    slst = [max(lst[0], 0)]
    for i in range(1, N):
        slst.append(max(slst[-1], 0) + lst[i])
    temp = max(slst)
    print(((sum(lst)+max(slst)*(pow(2, K, mod)-1)) % mod + mod) % mod)
