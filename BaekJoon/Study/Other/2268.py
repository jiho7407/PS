import sys
input = sys.stdin.readline

N, M = map(int, input().split())

tree = [0 for i in range(2*N)]
for i in range(M):
    cmd, p, q = map(int, input().split())
    if cmd == 0:
        if p > q:
            p, q = q, p
        ans = 0
        left = N+p-1
        right = N+q
        while left < right:
            if left % 2:
                ans += tree[left]
                left += 1
            if right % 2:
                right -= 1
                ans += tree[right]
            left //= 2
            right //= 2
        print(ans)
    else:
        idx = N+p-1
        tree[idx] = q
        idx //= 2
        while idx >= 1:
            tree[idx] = tree[idx*2] + tree[idx*2+1]
            idx //= 2
