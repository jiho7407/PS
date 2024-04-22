import sys
input = sys.stdin.readline

N = int(input())
up = [*map(int, input().split())]
down = [*map(int, input().split())]
machine_dict = {}
for i in range(N):
    machine_dict[up[i]] = i+1
for i in range(N):
    down[i] = machine_dict[down[i]]

tree = [0 for i in range(2*N)]

ans = 0
for i in range(N):
    cur = down[i]
    left = cur + N - 1
    right = 2*N
    cnt = 0
    while left < right:
        if left % 2:
            cnt += tree[left]
            left += 1
        if right % 2:
            right -= 1
            cnt += tree[right]
        left //= 2
        right //= 2
    ans += cnt
    idx = cur + N - 1
    while idx >= 1:
        tree[idx] += 1
        idx //= 2
print(ans)
