import functools

N = int(input())

tempN = N
p = 2
lst = []
while tempN > 1:
    if p*p > tempN:
        lst.append(tempN)
        break
    if tempN % p:
        p += 1
        continue
    lst.append(p)
    tempN //= p


def custom_sort(a, b):
    if str(a) + str(b) > str(b) + str(a):
        return -1
    elif str(a) + str(b) < str(b) + str(a):
        return 1
    else:
        return 0


lst.sort(key=functools.cmp_to_key(custom_sort))

ans1 = ""
for cmd in lst:
    ans1 += str(cmd)

lst2 = []
N -= 1
while N >= 4:
    lst2.append(2)
    N //= 2
lst2.append(N)

ans2 = ""
lst2.sort(key=functools.cmp_to_key(custom_sort))
for cmd in lst2:
    ans2 += str(cmd)

print(int(ans1)+int(ans2))
