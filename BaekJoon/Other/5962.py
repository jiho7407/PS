import sys
input = sys.stdin.readline
mod = int(1e9)+9

N = int(input())
lst = [int(input()) for i in range(N)]
S = [(0, 0)]
for i in range(N):
    S.append((S[-1][0] + lst[i], i+1))

S.sort(key = lambda x: (x[0], x[1]))

N += 1
tree = [0]*(2*N)

Nidx = N
while Nidx > 0:
    tree[Nidx] = 1
    Nidx //= 2

ans = 0
answered = False
for i in range(N):

    if S[i][0] < 0 or S[i][1] == 0:
        continue

    cmd = S[i][1]

    temp = 0

    s = N
    e = N + cmd + 1
    while s < e:
        if s%2:
            temp += tree[s]
            s += 1
        if e%2:
            e -= 1
            temp += tree[e]
        s //= 2
        e //= 2
        
    idx = N + cmd
    while idx:
        tree[idx] += temp
        idx //= 2

    if cmd == N-1:
        print(tree[2*N-1]%mod)
        answered = True
        break
if not answered:
    print(0)