import sys
input = sys.stdin.readline

N, M = map(int, input().split())

S = [*map(int, input().split())]
T = [*map(int, input().split())]

S.reverse()
T.reverse()

pi = [0] * M
for i in range(1, M):
    k = pi[i-1]
    while k and T[k] != T[i]:
        k = pi[k-1]
    if T[k] == T[i]:
        k += 1
    pi[i] = k

D = [0] * N
red = [False] * N
if S[0] == T[0]:
    red[0] = True
    D[0] = 1
for i in range(1, N):
    k = D[i-1]
    while k and T[k] != S[i]:
        k = pi[k-1]
    if T[k] == S[i]:
        k += 1
        red[i] = True
        if k == M:
            k = pi[k-1]
    D[i] = k

lst = []
curlen = 0
curred = False
red.append(False)
for i in range(N+1):
    cmd = red[i]
    if curred:
        if cmd:
            curlen += 1
        else:
            curred = False
            lst.append(curlen)
            curlen = 0

    else:
        if cmd:
            curred = True
            curlen = 1

ans = 0
for cmd in lst:
    ans ^= cmd
if ans:
    print("First")
else:
    print("Second")