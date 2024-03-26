import sys
input = sys.stdin.readline


def negcnt(lst):
    cnt = 0
    for i in range(max(blst)):
        if lst[i] < 0:
            cnt += 1
    return cnt


for TC in range(int(input())):
    n, k, d = map(int, input().split())
    lst = [*map(int, input().split())]
    blst = [*map(int, input().split())]
    for i in range(n):
        lst[i] -= i+1
    ans = lst.count(0) + (d-1)//2
    for i in range(min(2*n, d-1)):
        for j in range(blst[i % k]):
            lst[j] += 1
        temp = lst.count(0)
        ans = max(ans, temp + (d-i-2)//2)
    print(ans)
