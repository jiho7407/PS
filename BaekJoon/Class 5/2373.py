from collections import deque
import sys

N = int(input())
lst = [*map(int, input().split())]
lst.sort()

mncom = 100000000000
for i in range(N - 2):
    left = i
    mid = i + 1
    right = N - 1
    while mid < right:
        temp = lst[left] + lst[mid] + lst[right]
        if abs(temp) < mncom:
            mncom = abs(temp)
            ans = [lst[left], lst[mid], lst[right]]
        if temp == 0:
            break
        elif temp < 0:
            mid += 1
        else:
            right -= 1
ans.sort()
print(*ans)
