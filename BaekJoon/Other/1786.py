import sys
input = sys.stdin.readline

T = input().rstrip()
P = input().rstrip()

K = [0] * len(P)
j = 0
for i in range(1, len(P)):
    while(j>0 and (P[i] != P[j])):
        j = K[j-1]
    if P[i] == P[j]:
        j += 1
        K[i] += j

ans = []
j = 0
for i in range(len(T)):
    while(j>0 and (T[i] != P[j])):
        j = K[j-1]
    if T[i] == P[j]:
        if j == len(P)-1:
            ans.append(i-len(P)+2)
            j = K[j]
        else:
            j += 1
print(len(ans))
print(*ans)