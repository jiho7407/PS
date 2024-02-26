import sys
input = sys.stdin.readline

for TC in range(int(input())):
    N = int(input())
    reds = [0] * N
    for i in range(N-1):
        lst = [*map(int, input().split())]
        reds[i] += sum(lst)
        for j in range(len(lst)):
            reds[i+j+1] += lst[j]
    cnt = 0
    for cmd in reds:
        cnt += cmd*(N-1-cmd)
    print(N*(N-1)*(N-2)//6 - cnt//2)
