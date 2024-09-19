from math import log

ret = 0

lst = [*map(str, input().split())]

for a in lst:
    num = (6 - int(a[1]))
    if a[0] in ['b', 'B']:
        num += 0
    elif a[0] in ['s', 'S']:
        num += 5
    elif a[0] in ['g', 'G']:
        num += 10
    elif a[0] in ['p', 'P']:
        num += 15
    elif a[0] in ['d', 'D']:
        num += 20
    elif a[0] in ['r', 'R']:
        num += 25
    ret += pow(2.4, num)

print(log(ret, 2.4))
