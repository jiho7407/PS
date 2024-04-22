import sys

input = sys.stdin.readline


def findroot(a):
    if a == root[a]:
        return a
    root[a] = findroot(root[a])
    return root[a]


def merge(a, b):
    aroot = findroot(a)
    broot = findroot(b)
    if aroot == broot:
        if a == aroot:
            return
        elif b == broot:
            root[aroot] = a
            root[a] = a
            return
        else:
            print("Error")
            return
    root[broot] = aroot


N, M = map(int, input().split())
root = [i for i in range(N)]
name = []
dct = dict()
for i in range(N):
    lst = input().split()
    name.append(lst[-1])
    dct[lst[-1]] = i

for i in range(M):
    A, B, W = map(str, input().rstrip().split(","))
    A = A.split()
    B = B.split()
    if W == "1":
        merge(dct[A[-1]], dct[B[-1]])
    else:
        merge(dct[B[-1]], dct[A[-1]])

ans = []
for i in range(N):
    if i == findroot(i):
        ans.append(name[i])
ans.sort()
print(len(ans))
for an in ans:
    print(f"Kingdom of {an}")
