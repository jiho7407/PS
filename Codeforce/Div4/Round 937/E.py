import sys
input = sys.stdin.readline


def div(N):
    lst = [1]
    num = 2
    while N > 1:
        if num*num > N:
            lst.append(N)
            break
        if not N % num:
            lst.append(num)
            lst.append(N//num)
        num += 1
    lst.sort()
    return lst


def solve(N, M, S):
    dif = 0
    for i in range(N):
        if S[i] != S[i % M]:
            dif += 1
    if dif <= 1:
        return True

    dif = 0
    for i in range(N):
        if S[i] != S[i % M + M]:
            dif += 1
            if dif > 1:
                return False
    return True


for TC in range(int(input())):
    N = int(input())
    cmd = input().rstrip()
    nums = div(N)
    for num in nums:
        if solve(N, num, cmd):
            print(num)
            break
