import sys

input = sys.stdin.readline

N, K = map(int, input().split())
lst1 = []
lst2 = []
for i in range(N):
    a = int(input())
    if a == 0:
        continue
    elif a > 0:
        lst1.append(a)
    else:
        lst2.append(a * (-1))


def calc(lst):
    if not lst:
        return 0
    lst.sort(reverse=True)
    ret = 0
    for i in range(len(lst)):
        if i % K == 0:
            ret += lst[i]
    return ret


print((calc(lst1) + calc(lst2)) * 2)
