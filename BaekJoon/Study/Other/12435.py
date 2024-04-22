import sys
input = sys.stdin.readline

mx = 1000001
factor = [1] * mx
cnt = [0] * mx

for i in range(2, mx):
    for j in range(i*2, mx, i):
        cnt[j] += 1
    if factor[i] == 1:
        for j in range(i*2, mx, i):
            if factor[j] != 1:
                continue
            factor[j] = i

T = int(input())
for i in range(T):
    N, M = map(int, input().split())
    ans = 0
    for j in range(2, N):
        if cnt[N] == cnt[j] and factor[j] >= M:
            ans += 1
    print(f"Case #{i+1}: {ans}")