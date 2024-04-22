import sys
input = sys.stdin.readline

N = int(input())
rank = [[] for i in range(N)]

board = []
for i in range(3):
    board.append([*map(int, input().split())])
    for j in range(N):
        rank[board[i][j]-1].append(j+1)

rank.sort()

cnt = 0
tempset = set()
tree = [int(1e6) for i in range(2*N)]
for i in range(N):
    mn = 1e6
    cmd = rank[i][1]
    left = N
    right = N+cmd
    while left < right:
        if left % 2:
            mn = min(mn, tree[left])
            left += 1
        if right % 2:
            right -= 1
            mn = min(mn, tree[right])
        left //= 2
        right //= 2
    if rank[i][2] < mn:
        cnt += 1
    idx = N+cmd-1
    tree[idx] = rank[i][2]
    while idx > 1:
        idx //= 2
        tree[idx] = min(tree[idx*2], tree[idx*2+1])
print(cnt)
