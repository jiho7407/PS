import sys
input = sys.stdin.readline

S = int(input())
N, M = map(int, input().split())
lstN = []
lstM = []
for i in range(N):
    lstN.append(int(input()))
for i in range(M):
    lstM.append(int(input()))

Ndic = dict()
for i in range(N):
    cmd = 0
    for j in range(N-1):
        cmd += lstN[(i+j) % N]
        if cmd in Ndic:
            Ndic[cmd] += 1
        else:
            Ndic[cmd] = 1
Ndic[sum(lstN)] = 1
Ndic[0] = 1

ans = 0

for i in range(M):
    cmd = 0
    for j in range(M-1):
        cmd += lstM[(i+j) % M]
        if S-cmd in Ndic:
            ans += Ndic[S-cmd]
if S - sum(lstM) in Ndic:
    ans += Ndic[S-sum(lstM)]
if S in Ndic:
    ans += Ndic[S]

print(ans)
