import sys
input = sys.stdin.readline

N = int(input())
lst = [*map(int, input().split())]

numset = set()


def btr(a, cursum):
    if a == N:
        numset.add(cursum)
        return
    btr(a+1, cursum)
    btr(a+1, cursum+lst[a])


btr(0, 0)
i = 1
while True:
    if i in numset:
        i += 1
        continue
    break
print(i)
