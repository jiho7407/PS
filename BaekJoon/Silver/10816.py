import sys
input = sys.stdin.readline

N = int(input())
lst = [*map(int, input().split())]
lst.sort()
M = int(input())


def lower_bound(lst, num):
    ok, ng = -1, len(lst)
    while ng - ok > 1:
        mid = (ok + ng) // 2
        if lst[mid] < num:
            ok = mid
        else:
            ng = mid
    return ok


def upper_bound(lst, num):
    ok, ng = -1, len(lst)
    while ng - ok > 1:
        mid = (ok + ng) // 2
        if lst[mid] <= num:
            ok = mid
        else:
            ng = mid
    return ok


qlst = [*map(int, input().split())]
for a in qlst:
    lo = lower_bound(lst, a)
    up = upper_bound(lst, a)
    print(up - lo, end=" ")
