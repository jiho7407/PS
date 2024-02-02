import sys
input = sys.stdin.readline

N, M = map(int, input().split())
tree = [0] * (2*N)

lst = []
for i in range(M):
    lst.append(tuple(map(int, input().split())))
lst.sort(key=lambda x:(x[0], x[1]))

ans = 0
for i, cmd in lst:

    #query
    s = cmd + N
    e = 2*N
    temp = 0
    while s < e:
        if s%2:
            temp += tree[s]
            s += 1
        if e%2:
            e -= 1
            temp += tree[e]
        s //= 2
        e //= 2
    ans += temp

    #update
    idx = N + cmd - 1
    while idx:
        tree[idx] += 1
        idx //= 2
        
print(ans)