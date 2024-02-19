import sys
input = sys.stdin.readline
sys.setrecursionlimit(5*int(1e5)+1000)

N = int(input())
lst = [input().rstrip() for i in range(N)]
nxt = [i for i in range(N+1)]
front = [i for i in range(N+1)]
back = [i for i in range(N+1)]

def findfront(a):
    if a == front[a]:
        return a
    front[a] = findfront(front[a])
    return front[a]

def findback(a):
    if a == back[a]:
        return a
    back[a] = findback(back[a])
    return back[a]

def merge(a, b):
    af = findfront(a)
    ab = findback(a)
    bf = findfront(b)
    bb = findback(b)
    front[bf] = af
    back[ab] = bb
    nxt[ab] = bf

for i in range(N-1):
    a, b = map(int, input().split())
    merge(a, b)

idx = findfront(1)
while idx != nxt[idx]:
    print(lst[idx-1], end="")
    idx = nxt[idx]
print(lst[idx-1])