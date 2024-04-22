import sys
input = sys.stdin.readline

N = int(input())
lst = [*map(int, input().split())]

pflst = [0]
for i in range(N):
    pflst.append(pflst[-1]+lst[i])
for i in range(N):
    pflst.append(pflst[-1]+lst[i])
cnt = 0
for i in range(N):
    for j in range(i+1, i+N+1):
        cmd = pflst[j]-pflst[i]
        if cmd < 0:
            cnt -= cmd//pflst[N]
print(cnt)
