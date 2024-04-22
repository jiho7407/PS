import sys
input = sys.stdin.readline

T = int(input())
n = int(input())
arra = [*map(int,input().split())]
m = int(input())
arrb = [*map(int,input().split())]

sumarra = [0]
for i in range(n):
    sumarra.append(sumarra[-1] + arra[i])
sumarrb = [0]
for i in range(m):
    sumarrb.append(sumarrb[-1] + arrb[i])

partsuma = []
partsumbdict = {}
for i in range(n):
    for j in range(i+1, n+1):
        partsuma.append(sumarra[j] - sumarra[i])
for i in range(m):
    for j in range(i+1, m+1):
        temp = sumarrb[j] - sumarrb[i]
        if temp in partsumbdict:
            partsumbdict[temp] += 1
        else:
            partsumbdict[temp] = 1

ans = 0
for i in partsuma:
    if T-i in partsumbdict:
        ans += partsumbdict[T-i]
print(ans)