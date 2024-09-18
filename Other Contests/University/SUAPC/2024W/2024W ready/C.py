import sys
input = sys.stdin.readline
sys.setrecursionlimit(5*int(1e5)+100)

N, Q = map(int, input().split())

lst = [0]
end = [0]

stk = [(-1, 0)]
idx = 0

for i in range(N):
    l, t = input().split()
    l = int(l)
    while stk and stk[-1][0] >= l:
        end[stk[-1][1]] = idx
        stk.pop()
    lst[stk[-1][1]] += 1
    if t == "h":
        idx += 1
        lst.append(0)
        end.append(0)
        stk.append((l, idx))
while stk:
    end[stk[-1][1]] = idx
    stk.pop()

treeN = len(lst)

tree = [0] * (2*treeN)
for i in range(treeN):
    tree[treeN+i] = lst[i]

for i in range(treeN-1, 0, -1):
    tree[i] = tree[i*2] + tree[i*2+1]

def update(idx, value):
    idx += treeN
    while idx:
        tree[idx] += value
        idx //= 2

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
        s //= 2
        e //= 2
    return temp

fold = [False] * treeN
for q in range(Q):
    # print(tree)
    cmd = list(input().split())
    if cmd[0] == "p":
        print(tree[1])
        continue
    cmd = int(cmd[1])
    val = lst[cmd] + query(cmd+1, end[cmd])
    if fold[cmd]:
        fold[cmd] = False
        update(cmd, val)
    else:
        fold[cmd] = True
        update(cmd, -val)