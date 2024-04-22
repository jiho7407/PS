import math

mx = int(1e5)+1

mu = [-1] * mx
mu[0] = 0
mu[1] = 1
for i in range(2, mx):
    for j in range(2*i, mx, i):
        mu[j] -= mu[i]

def SFI(N):
    temp = 0
    for i in range(1, math.floor(math.sqrt(N))+1):
        temp += mu[i] * (N//(i*i))
    return temp

G = int(input())

left = 1
right = 2*int(1e9)

ans = 0

while left <= right:
    mid = (left + right) // 2
    
    result = SFI(mid)
    if result < G:
        left = mid + 1
    else:
        right = mid-1
        ans = mid

print(ans)