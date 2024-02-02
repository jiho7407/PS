N, M, C = map(int, input().split())

B = [*map(int, input().split())]

ans = 0
for i in range(N):
    A = [*map(int, input().split())]
    temp = C
    for j in range(M):
        temp += A[j] * B[j]
    if temp>0:
        ans += 1
print(ans)