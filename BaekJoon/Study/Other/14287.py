import sys
input = sys.stdin.readline
sys.setrecursionlimit(2*int(1e5))

N, M = map(int, input().split())

links = [[] for i in range(N+1)]

linklst = [*map(int, input().split())]

for i in range(1, N):
    cmd = linklst[i]
    links[cmd].append(i+1)

S = [0] * (N+1)
E = [0] * (N+1)

cnt = 0


def maketree(a):
    global cnt
    cnt += 1
    S[a] = cnt
    for goal in links[a]:
        maketree(goal)
    E[a] = cnt


segtree = [0] * (2*N)


def getsum(a):
    left = N + S[a] - 1
    right = N + E[a]
    temp = 0
    while left < right:
        if left % 2:
            temp += segtree[left]
            left += 1
        if right % 2:
            right -= 1
            temp += segtree[right]
        left //= 2
        right //= 2
    return temp


def update(a, value):
    idx = N + S[a]-1
    while idx:
        segtree[idx] += value
        idx //= 2


maketree(1)

for i in range(M):
    cmd, *var = map(int, input().split())
    if cmd == 1:
        a, v = var
        update(a, v)
    else:
        print(getsum(var[0]))
    print(segtree)
print(S, E)
