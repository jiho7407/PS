import sys
input = sys.stdin.readline

N, K = map(int, input().split())
H = [*map(int, input().split*())]
A = [*map(int, input().split*())]
B = [*map(int, input().split*())]

left = 1
right = max(H)

ans = int(1e10)
while left<right:
    mid = (left + right)//2
    
    cost = 0
    for i in range(K):
        if H[i] < mid:
            cost += (mid-H[i])*A[i]
        else:
            cost += (H[i]-mid)*B[i]

    temp = cost
    for i in range(N-K):
        if H[i] < mid:
            cost -= (mid-H[i])*A[i]
        else:
            cost -= (H[i]-mid)*B[i]

        if H[i+K] < mid:
            cost += (mid-H[i+K])*A[i+K]
        else:
            cost += (H[i+K]-mid)*B[i+K]
        cost = min(temp, cost)
    
    