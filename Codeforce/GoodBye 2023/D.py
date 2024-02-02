import sys
input = sys.stdin.readline

lst5 = [16384, 31684, 36481, 38416, 43681]


def sq(n):
    if (n**0.5).is_integer():
        return True
    else:
        return False


for TC in range(int(input())):
    N = int(input())
    if N == 1:
        print(1)
        continue
    if N == 3:
        print(169)
        print(196)
        print(961)
        continue
    if N == 5:
        for i in range(5):
            print(lst5[i])
        continue
    lst = []
    for i in range(N//2):
        lst.append(10**(N//2)+3*(10**i))
        lst.append(3*10**(N//2)+(10**i))
    lst.append(247*10**(N//2-2))
    for i in range(N):
        print(lst[i]**2)
