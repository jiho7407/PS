N, K, M = map(int, input().split())

lst = [i for i in range(N)]
used = [False] * N

idx = 0
cnt = 0
idxcnt = 0
reverse = False
while cnt < N:
    if idxcnt == K and not used[idx]:
        if idx:
            print(idx)
        else:
            print(N)
        used[idx] = True
        cnt += 1
        if cnt % M == 0:
            reverse = not reverse
        idxcnt = 0
        if cnt == N:
            break
    if reverse:
        idx -= 1
        if idx < 0:
            idx = N - 1
        if not used[idx]:
            idxcnt += 1
    else:
        idx += 1
        if idx >= N:
            idx = 0
        if not used[idx]:
            idxcnt += 1
