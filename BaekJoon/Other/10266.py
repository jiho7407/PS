N = int(input())

lst = [*map(int, input().split())]
lst.sort()

S = []
for i in range(N-1):
    S.append(lst[i+1]-lst[i])
S.append(lst[0]+360000-lst[N-1])

lst = [*map(int, input().split())]
lst.sort()

P = []
for i in range(N-1):
    P.append(lst[i+1]-lst[i])
P.append(lst[0]+360000-lst[N-1])

pi = [0] * N
j = 0

for i in range(1, N):
    while j>0 and (P[i] != P[j]):
        j = pi[j-1]
    if P[i] == P[j]:
        j += 1
        pi[i] = j

S += S[:-1]

j = 0
pos = False
for i in range(2*N-1):
    if pos:
        break
    while j>0 and (S[i] != P[j]):
        j = pi[j-1]
    if S[i] == P[j]:
        if j == N-1:
            pos = True
            j = pi[j]
        else:
            j += 1

if pos:
    print("possible")
else:
    print("impossible")
