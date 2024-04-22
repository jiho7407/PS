import sys
input = sys.stdin.readline

N, K = map(int, input().split())
lst = [*map(int, input().split())]
rank = [[] for i in range(K+1)]
for i in range(K):
    cmd = lst[i]
    rank[cmd].append(i)
for i in range(1, K+1):
    rank[i].append(K+1)

on = [0 for i in range(K+1)]
ans = 0
for i in range(K):
    cmd = lst[i]
    if on[cmd]:
        continue
    if sum(on) < N:
        on[cmd] = 1
        continue
    ans += 1

    time = [K+1 for i in range(K+1)]
    for k in range(i+1, K):
        num = lst[k]
        if time[num] == K+1:
            time[num] = k
    idx = 0
    mx = 0
    for k in range(1, K+1):
        if not on[k]:
            continue
        if time[k] > mx:
            idx = k
            mx = time[k]
    on[idx] = 0
    on[cmd] = 1
print(ans)
