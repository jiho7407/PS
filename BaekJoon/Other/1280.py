import sys
input = sys.stdin.readline

mod = int(1e9)+7
N = 200001

tree = [0 for i in range(2*N)]
cntree = [0 for i in range(2*N)]


def update(a):
    global tree
    global cntree
    idx = N+a-1
    while idx >= 1:
        tree[idx] += a
        cntree[idx] += 1
        idx //= 2


def getsum(tree, left, right):
    ans = 0
    left += N-1
    right += N
    while left < right:
        if left % 2:
            ans += tree[left]
            left += 1
        if right % 2:
            right -= 1
            ans += tree[right]
        left //= 2
        right //= 2
    return ans


ans = 1
for TC in range(int(input())):
    cmd = int(input()) + 1
    temp = 0
    temp += cmd * getsum(cntree, 1, cmd-1) - getsum(tree, 1, cmd-1)
    temp += getsum(tree, cmd+1, N) - cmd * getsum(cntree, cmd+1, N)
    update(cmd)
    if TC == 0:
        continue
    ans *= temp % mod
    ans %= mod
print(ans)
