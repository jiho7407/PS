import sys
import random
input = sys.stdin.readline

N, M = map(int, input().split())


E = []
for i in range(M):
    u, v, c = map(int, input().split())
    E.append((u, v, c, i+1))

if N > M:
    print("NO")
    sys.exit()
    
def findroot(a):
    if a == root[a]:
        return a
    
    root[a] = findroot(root[a])
    return root[a]

def union(a, b):
    aroot = findroot(a)
    broot = findroot(b)

    if aroot == broot:
        return False
    
    if aroot < broot:
        root[broot] = aroot
    else:
        root[aroot] = broot
    
    return True

E.sort(key=lambda x: x[2])

root = [i for i in range(N+1)]

connect = 0
ans = []
for i in range(0, M):
    u, v, c, idx = E[i]
    if not union(u, v):
        root = [i for i in range(N+1)]
        union(u, v)
        ans.append(idx)
        connect += 1
        break

for i in range(0, M):
    if connect == N-1:
        break
    u, v, c, idx = E[i]
    if union(u, v):
        ans.append(idx)
        connect += 1

print("YES")
print(*ans)