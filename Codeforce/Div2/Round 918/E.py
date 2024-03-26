import sys
input = sys.stdin.readline

for TC in range(int(input())):
    n = int(input())
    lst = [*map(int, input().split())]
    pfsum = [0]
    for i in range(n):
        if i % 2:
            pfsum.append(pfsum[-1] - lst[i])
        else:
            pfsum.append(pfsum[-1] + lst[i])
    pfsum.sort()
    ans = "NO"
    for i in range(n):
        if pfsum[i] == pfsum[i+1]:
            ans = "YES"
            break
    print(ans)
