import sys
input = sys.stdin.readline

N, M, K = map(int, input().split())
cards = [*map(int, input().split())]
cards.sort()
roots = [*range(M+1)]
games = [*map(int, input().split())]
idxs = [0 for i in range(cards[0])]
for i in range(1, M):
    idxs.extend([i for j in range(cards[i]-cards[i-1])])


def root(a):
    if a == roots[a]:
        return a
    roots[a] = root(roots[a])
    return roots[a]


def merge(a, b):
    aroot = root(a)
    broot = root(b)
    if aroot != broot:
        if aroot > broot:
            roots[broot] = aroot
        else:
            roots[aroot] = broot
        return True
    return False


for i in range(K):
    idx = root(idxs[games[i]])
    print(cards[idx])
    if i == K-1:
        break
    merge(idx, idx+1)
