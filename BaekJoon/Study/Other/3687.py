import sys
input = sys.stdin.readline

nums = [6, 2, 5, 5, 4, 5, 6, 3, 7, 6]
ms = ["0", "0", "1", "7", "4", "2", "6", "8"]
ms2 = ["8", "10", "18", "22", "20", "28", "68"]

for TC in range(int(input())):
    N = int(input())
    m = ''
    M = ''

    if N == 2:
        print(1, 1)
        continue

    if N % 2:
        M += "7"
        for i in range((N-3)//2):
            M += "1"
    else:
        for i in range(N//2):
            M += "1"

    if N <= 7:
        m = ms[N]
    elif N % 7 == 3:
        if N == 10:
            m = "22"
        else:
            m = "200" + "8"*(N//7-2)
    else:
        m += ms2[N % 7]
        m += "8" * (N//7-1)
    print(m, M)
