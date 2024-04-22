import sys
input = sys.stdin.readline

for TC in range(int(input())):
    N = int(input())
    lst = [*map(int, input().split())]
    cnt = [0] * 101
    for i in lst:
        cnt[i] += 1
    ans = 0
    for i in range(101):
        ans += cnt[i] // 3
    print(ans)
