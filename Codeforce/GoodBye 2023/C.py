import sys
input = sys.stdin.readline


def calc(i, j):
    return ((i+j)//2) * 2


for TC in range(int(input())):
    N = int(input())
    lst = [*map(int, input().split())]
    pfsum = [lst[0]]
    odds = [0]
    evens = [0]
    if lst[0] % 2:
        odds[0] += 1
    else:
        evens[0] += 1
    for i in range(N-1):
        cmd = lst[i+1]
        pfsum.append(pfsum[-1]+cmd)
        if cmd % 2:
            evens.append(evens[-1])
            odds.append(odds[-1]+1)
        else:
            evens.append(evens[-1]+1)
            odds.append(odds[-1])
    for i in range(N):
        if i == 0:
            print(pfsum[0], end=' ')
            continue
        temp = odds[i]//3
        if odds[i] % 3 == 1:
            temp += 1
        print(pfsum[i]-temp, end=' ')
    print()
