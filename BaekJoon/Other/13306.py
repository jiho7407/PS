import sys
input = sys.stdin.readline
sys.setrecursionlimit(3*int(1e5))

N, Q = map(int, input().split())

parent = [0] * (N+1)
parent[1] = 1
for i in range(N-1):
    cmd = int(input())
    parent[i+2] = cmd

query = []
for i in range(N+Q-1):
    query.append(tuple(map(int, input().split())))

tree = [i for i in range(N+1)]
query.reverse()


def findroot(a):
    idx = a
    while tree[idx] != idx:
        tree[idx] = findroot(tree[idx])
        idx = tree[idx]
    return idx


anslst = []

for q in query:
    cmd, *nums = q
    if cmd:
        c, d = nums
        if findroot(c) == findroot(d):
            anslst.append("YES")
        else:
            anslst.append("NO")
        continue
    b = nums[0]
    tree[b] = parent[b]

anslst.reverse()
for ans in anslst:
    print(ans)
