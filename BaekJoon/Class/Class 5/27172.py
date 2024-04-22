import sys

input = sys.stdin.readline

N = int(input())
lst = [*map(int, input().split())]
numset = set(lst)
numlst = [0 for i in range(1000001)]
for i in lst:
    temp = 2 * i
    while temp < 1000001:
        if temp in numset:
            numlst[temp] -= 1
            numlst[i] += 1
        temp += i
for i in lst:
    print(numlst[i], end=" ")
