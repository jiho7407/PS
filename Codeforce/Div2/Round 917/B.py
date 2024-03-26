import sys
input = sys.stdin.readline

for TC in range(int(input())):
    N = int(input())
    cmd = input().rstrip()
    alphabet = [False for i in range(26)]
    cnt = 0
    usedcnt = 0
    for i in range(N):
        alp = ord(cmd[i])-97
        if alphabet[alp]:
            cnt += usedcnt
        else:
            usedcnt += 1
            alphabet[alp] = True
            cnt += usedcnt
    print(cnt)
