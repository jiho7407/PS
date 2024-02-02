mod = int(1e9) + 7

N, K = map(int, input().split())
A = [*map(int, input().split())]

inv = 0
for i in range(N-1):
    for j in range(i+1, N):
        if A[i] > A[j]:
            inv += 1

inv2 = 0
temp = 0
temp2 = 1
A.sort()
for i in range(1, N):
    if A[i-1] < A[i]:
        temp += temp2
        temp2 = 0
    inv2 += temp
    temp2 += 1

ans = 0
ans += (inv * K) % mod

cnt = (K*(K-1))//2
ans += (cnt % mod) * inv2

print(ans % mod)
