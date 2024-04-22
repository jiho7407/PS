import sys
input = sys.stdin.readline

N, Q = map(int, input().split())
tree = [0 for i in range(2*N)]

for i in range(Q):
    cmd, p, q = map(int, input().split())
    if cmd == 1:
        idx = N+p-1
        while idx >= 1:
            tree[idx] += q
            idx //= 2
    else:
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
