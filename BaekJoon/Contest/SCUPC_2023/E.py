import sys
input = sys.stdin.readline

N = int(input())
lst = [*map(int, input().split())]
lst.sort()
temp = lst[-1]*lst[-1]
for i in range(N-1):
    temp ^= lst[i]*lst[i]
    temp ^= lst[i]*lst[i+1]
print(temp)
