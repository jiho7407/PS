import sys
input = sys.stdin.readline

N, M = map(int, input().split())
lst = [int(input()) for i in range(N)]
lst.sort()

D = []
for i in range(N-1):
    D.append(lst[i+1] - lst[i])

left = 1
right = int(1e9)
ans = 0
while left<=right:
    cnt = 0
    mid = (left + right)//2

    cursum = 0
    for i in range(N-1):
        cursum += D[i]
        if cursum >= mid:
            cursum = 0
            cnt += 1

    if cnt >= M-1:
        ans = mid
        left = mid + 1
    else:
        right = mid - 1
print(ans)