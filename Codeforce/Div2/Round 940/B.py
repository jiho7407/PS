import sys
input = sys.stdin.readline

for TC in range(int(input())):
    n, k = map(int, input().split())
    if n == 1:
        print(k)
        continue
    ans = []
    b = bin(k)[2:]
    ans.append((1 << len(b)-1)-1)
    ans.append(k - (1 << len(b)-1)+1)
    for i in range(n-2):
        ans.append(0)
    print(*ans)
