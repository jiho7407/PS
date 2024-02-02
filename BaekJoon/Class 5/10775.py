import sys
input = sys.stdin.readline
sys.setrecursionlimit(int(1e5))

G = int(input())
P = int(input())

Docked = [*range(G+1)]


def findgate(a):
    if a == Docked[a]:
        return a
    Docked[a] = findgate(Docked[a])
    return Docked[a]


ans = 0
closed = False

for i in range(P):
    airplane = int(input())
    if closed:
        continue
    lastdocked = findgate(airplane)
    if not lastdocked == 0:
        ans += 1
        Docked[lastdocked] = lastdocked-1
    else:
        closed = True
        continue

print(ans)
