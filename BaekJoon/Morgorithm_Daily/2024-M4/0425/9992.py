import sys
input = sys.stdin.readline

for TC in range(int(input())):
    N, M = map(int, input().split())
    ans = int(1e9)
    for i in range(len(bin(M))-2):
        temp = 0
        tempN, tempM = N, M >> i
        while (tempN > tempM):
            if tempN % 2:
                tempN += 1
            else:
                tempN //= 2
            temp += 1
        temp += tempM-tempN
        if (i == 0):
            ans = min(ans, temp)
            continue
        left = bin(M)[2:][-i:]
        temp += len(left)
        temp += left.count('1')
        ans = min(ans, temp)
    print(ans)
