import sys
input = sys.stdin.readline

N, M = map(int, input().split())
root = [*range(N+1)]
links = []
for i in range(M):
    links.append([*map(int, input().split())])
links.sort(key=lambda x: x[2])

# Union Find


def findroot(x):
    if x == root[x]:
        return x
    root[x] = findroot(root[x])
    return root[x]


def merge(a, b):
    aroot = findroot(a)
    broot = findroot(b)
    if aroot != broot:
        if aroot > broot:
            root[aroot] = broot
        else:
            root[broot] = aroot
        return True
    return False


# solve
cnt = 1
ans = 0
for i in range(M):
    if cnt == N-1:
        break
    s, e, cost = links[i]
    if not merge(s, e):
        continue
    ans += cost
    cnt += 1
print(ans)
