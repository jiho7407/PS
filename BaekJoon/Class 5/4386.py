import sys
input = sys.stdin.readline

N = int(input())

roots = [*range(N+1)]
stars = []
for i in range(N):
    stars.append([*map(float, input().split())])

links = []
for i in range(N-1):
    for j in range(i+1, N):
        links.append([i+1, j+1, ((stars[j][0]-stars[i][0])**2 +
                     (stars[j][1]-stars[i][1])**2)**(0.5)])

links.sort(key=lambda x: x[2])


def findroot(a):
    while a != roots[a]:
        a = roots[a]
    return a


def merge(a, b):
    aroot = findroot(a)
    broot = findroot(b)
    if aroot != broot:
        if aroot > broot:
            roots[aroot] = broot
        else:
            roots[broot] = aroot
        return True
    return False


idx = 0
cnt = 1
ans = 0
while cnt < N:
    s, e, cost = links[idx]
    if merge(s, e):
        cnt += 1
        ans += cost
    idx += 1

print(ans)
