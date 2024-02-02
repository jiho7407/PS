import sys
input = sys.stdin.readline

for TC in range(int(input())):
    N = int(input())
    templst = []
    for i in range(N):
        templst.append([*map(int, input().split())])
    templst.sort()

    lst = []
    for i in range(N):
        lst.append([i+1, templst[i][1]])
    lst.sort(key=lambda x: x[1])

    tree = [0 for i in range(2*N)]
    ans = 0
    for num, value in lst:
        a = N+num-1
        b = 2*N
        while a < b:
            if a % 2:
                ans += tree[a]
                a += 1
            if b % 2:
                b -= 1
                ans += tree[b]
            b //= 2
            a //= 2
        idx = N+num-1
        while idx >= 1:
            tree[idx] += 1
            idx //= 2
    print(ans)
