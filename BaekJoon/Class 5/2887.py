import sys
input = sys.stdin.readline

N = int(input())
planet = []
links = []
for i in range(N):
    planet.append([i] + [*map(int, input().split())])

planet.sort(key=lambda x: x[1])
for i in range(N-1):
    links.append([planet[i][0], planet[i+1][0],
                 abs(planet[i+1][1]-planet[i][1])])
planet.sort(key=lambda x: x[2])
for i in range(N-1):
    links.append([planet[i][0], planet[i+1][0],
                 abs(planet[i+1][2]-planet[i][2])])
planet.sort(key=lambda x: x[3])
for i in range(N-1):
    links.append([planet[i][0], planet[i+1][0],
                 abs(planet[i+1][3]-planet[i][3])])

links.sort(key=lambda x: x[2])

root = [*range(N+1)]


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


cnt = 1
ans = 0
for s, e, cost in links:
    if cnt == N:
        break
    if merge(s, e):
        ans += cost
        cnt += 1

print(ans)
