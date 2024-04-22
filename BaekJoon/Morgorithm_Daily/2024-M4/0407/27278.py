import sys
input = sys.stdin.readline

N, M = map(int, input().split())
times = [*map(int, input().split())]
pfsum = [0]
for i in range(N):
    pfsum.append(pfsum[-1]+times[i])

ans = 0
for i in range(M):
    s, e, t = map(int, input().split())
    s -= 1
    e -= 1
    intime = pfsum[e] - pfsum[s]
    if s > e:
        intime += pfsum[-1]
    waittime = pfsum[s] + ((t - pfsum[s]-1)//pfsum[-1]+1)*pfsum[-1]
    ans = max(ans, waittime+intime)
print(ans)
