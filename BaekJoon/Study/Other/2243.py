import sys
input = sys.stdin.readline

N = 1000000
tree = [0 for i in range(2*N)]


def getsum(right):
    left = N
    right += N
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
    return cnt


for TC in range(int(input())):
    cmd = [*map(int, input().split())]
    if cmd[0] == 2:
        flavor = cmd[1]
        cnt = cmd[2]
        idx = flavor + N - 1
        while idx >= 1:
            tree[idx] += cnt
            idx //= 2
    else:
        rank = cmd[1]
        left = 1
        right = N
        while left < right:
            mid = (left + right) // 2
            temp = getsum(mid)
            if temp < rank:
                left = mid+1
            elif temp >= rank:
                right = mid
        print(left)
        idx = left + N - 1
        while idx >= 1:
            tree[idx] -= 1
            idx //= 2
