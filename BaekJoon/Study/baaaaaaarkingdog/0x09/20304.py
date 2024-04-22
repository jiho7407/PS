import sys
from collections import deque
input = sys.stdin.readline

N = int(input())
M = int(input())
numlst = [*map(int,input().split())]
dist = [-1 for i in range(N+1)]

powlst = []
tempi = 1
while tempi <= N:
    powlst.append(tempi)
    tempi *= 2

Q = deque()
for i in numlst:
    dist[i] = 0
    Q.append((i, 0))

while Q:
    curnum, curdst = Q.popleft()
    for i in powlst:
        temp = curnum^i
        if temp>N: continue
        if dist[temp] >= 0: continue
        dist[temp] = curdst+1
        Q.append((temp, curdst+1))
print(max(dist))