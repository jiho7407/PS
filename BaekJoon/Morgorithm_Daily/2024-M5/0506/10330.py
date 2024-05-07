import sys
input = sys.stdin.readline

N, M = map(int, input().split())
lst1 = [*map(int, input().split())]
lst2 = [*map(int, input().split())]

ones = []
for idx, num in enumerate(lst1):
    if num == 1:
        ones.append(idx)

ones2 = []
ones3 = []
cur = 0
for idx, num in enumerate(lst2):
    if idx % 2:
        for i in range(num):
            ones2.append(cur + i)
    else:
        for i in range(num):
            ones3.append(cur + i)
    cur += num


def compare(lst1, lst2):
    if len(lst1) != len(lst2):
        return int(1e9)
    ret = 0
    for i in range(len(lst1)):
        ret += abs(lst1[i] - lst2[i])
    return ret


print(min(compare(ones, ones2), compare(ones, ones3)))
