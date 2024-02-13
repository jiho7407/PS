N = int(input())

print(N * (N-1) // 2)
for i in range(N):
    print(2**i, end=" ")
print()
print(N-1)
for i in range(1, N+1):
    print(i, end=" ")
