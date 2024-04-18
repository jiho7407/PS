import sys
# sys.setrecursionlimit(10**6)
input = sys.stdin.readline

N = int(input())
S = input().rstrip()
lst = [*map(int, input().split())]

pf0 = [0]*(N+1)  # 0101...
pf1 = [0]*(N+1)  # 1010...
for i in range(N):
    if i % 2 == 0:
        if S[i] == '0':
            pf0[i+1] = pf0[i]
            pf1[i+1] = pf1[i]+lst[i]
        else:
            pf0[i+1] = pf0[i]+lst[i]
            pf1[i+1] = pf1[i]
    else:
        if S[i] == '0':
            pf0[i+1] = pf0[i]+lst[i]
            pf1[i+1] = pf1[i]
        else:
            pf0[i+1] = pf0[i]
            pf1[i+1] = pf1[i]+lst[i]

sf0 = [0]*(N+1)  # 0101...
sf1 = [0]*(N+1)  # 1010...

for i in range(N-1, -1, -1):
    if i % 2 == 0:
        if S[i] == '0':
            sf0[i] = sf0[i+1]
            sf1[i] = sf1[i+1]+lst[i]
        else:
            sf0[i] = sf0[i+1]+lst[i]
            sf1[i] = sf1[i+1]
    else:
        if S[i] == '0':
            sf0[i] = sf0[i+1]+lst[i]
            sf1[i] = sf1[i+1]
        else:
            sf0[i] = sf0[i+1]
            sf1[i] = sf1[i+1]+lst[i]

ans = int(1e18)

for i in range(1, N):
    ans = min(ans, pf0[i]+sf1[i])
    ans = min(ans, pf1[i]+sf0[i])

print(ans)
