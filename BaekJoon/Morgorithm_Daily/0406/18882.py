import sys
input = sys.stdin.readline

N, T = map(int, input().split())
result = list(input().rstrip())
res = [False] * N
for idx, cmd in enumerate(result):
    if cmd == '1':
        res[idx] = True

shakes = []
for i in range(T):
    t, x, y = map(int, input().split())
    shakes.append((t, x-1, y-1))
shakes.sort(key=lambda x: x[0])


def solve(cow, K):
    state = [-1] * N
    state[cow] = K
    for t, x, y in shakes:
        if state[x] >= 0 and state[y] >= 0:
            state[x] = max(0, state[x]-1)
            state[y] = max(0, state[y]-1)
        elif state[x] > 0:
            state[x] -= 1
            state[y] = K
        elif state[y] > 0:
            state[y] -= 1
            state[x] = K
    for i in range(N):
        if (res[i]) ^ (state[i] >= 0):
            return False
    return True


x = 0
y = 1000000
z = -1
for i in range(N):
    suc = False
    for k in range(T+1):
        if solve(i, k):
            suc = True
            y = min(y, k)
            z = max(z, k)
    if suc:
        x += 1
if z == T:
    z = "Infinity"
print(x, y, z)
