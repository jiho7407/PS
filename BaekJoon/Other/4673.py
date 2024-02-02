def d(N):
    temp = N
    while N > 0:
        temp += N % 10
        N //= 10
    return temp


N = 10000
lst = [True] * (N+1)

lst[0] = False

for i in range(1, N+1):
    if not lst[i]:
        continue
    cur = d(i)
    while True:
        if cur > N:
            break
        if not lst[cur]:
            break
        lst[cur] = False
        cur = d(cur)

for idx, cmd in enumerate(lst):
    if cmd:
        print(idx)
