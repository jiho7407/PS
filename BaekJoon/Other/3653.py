import sys
input = sys.stdin.readline


for TC in range(int(input())):
    n, M = map(int, input().split())
    N = n+M
    tree = [0 for i in range(2*N)]
    pos = [i for i in range(1, n+1)] + [0]
    pos.reverse()
    for i in range(n):
        tree[N+i] = 1
    for i in range(N-1, 0, -1):
        tree[i] = tree[2*i] + tree[2*i+1]
    lst = [*map(int, input().split())]
    for i in range(M):
        cmd = lst[i]
        ans = 0

        left = pos[cmd] + N
        right = 2*N
        while left < right:
            if left % 2:
                ans += tree[left]
                left += 1
            if right % 2:
                right -= 1
                ans += tree[right]
            left //= 2
            right //= 2

        idx = pos[cmd] + N-1
        while idx >= 1:
            tree[idx] -= 1
            idx //= 2
        idx = N+n+i
        while idx >= 1:
            tree[idx] += 1
            idx //= 2

        pos[cmd] = n+i+1
        print(ans, end=' ')
    print()
