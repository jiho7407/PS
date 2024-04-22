import sys
input = sys.stdin.readline
sys.setrecursionlimit(2*int(1e5)+2000)

N, Q = map(int, input().split())
treeN = N+1
tree = [0] * (2*treeN)
mod = 2**32

temprnn = 14972687
def rnn():
    global temprnn
    temprnn = temprnn * 11 + 7
    temprnn %= mod
    return temprnn

def update(a, v):
    idx = treeN + a
    while idx:
        tree[idx] += v
        tree[idx] %= mod
        idx //= 2
    return 0

def query(s, e):
    s += treeN
    e += treeN+1
    temp = 0
    while s<e:
        if s%2:
            temp += tree[s]
            s += 1
        if e%2:
            e -= 1
            temp += tree[e]
        temp %= mod
        s //= 2
        e //= 2
    return temp

links = [[]for i in range(N+1)]

for i in range(1, N):
    a = int(input())
    links[a].append(i+1)

idx = -1

start = [0] * (N+1)
end = [0] * (N+1)

def euler(a):
    global idx
    idx += 1
    start[a] = idx
    for goal in links[a]:
        euler(goal)
    end[a] = idx+1

euler(1)

for q in range(Q):
    b, c, d = map(int, input().split())
    bs, be = start[b], end[b]
    cs, ce = start[c], end[c]

    result = (query(0, bs)==query(0, cs))
    if result:
        print("YES")
    else:
        print("NO")

    if d:
        r = rnn()
        if result:
            update(bs, r)
            update(be, -r)
        else:
            update(cs, r)
            update(ce, -r)