import sys
import heapq
input = sys.stdin.readline


def oppo(x):
    if x == 'A':
        return 'B'
    return 'A'


N, M = map(int, input().split())
used = [False] * (2*N+1)
ans = [[] for i in range(M)]
end = [0] * M
query = []
for i in range(M):
    robot, BLOCK, num = map(str, input().split())
    used[int(num)] = True
    end[i] = int(num)
    query.append((robot, BLOCK, int(num)))
need = [False] * M
for i in range(M-1):
    if query[i][0] == query[i+1][0]:
        need[i] = True
if query[-1][0] == 'A':
    need[-1] = True

PQ = []
for i in range(M):
    if need[i]:
        heapq.heappush(PQ, (query[i][2], i))

cnt = 1
while PQ:
    num, idx = heapq.heappop(PQ)
    while cnt <= 2*N and (cnt <= num or used[cnt]):
        cnt += 1
    if cnt > 2*N:
        print("NO")
        sys.exit()
    ans[idx].append((oppo(query[idx][0]), "CHAIN", cnt))
    end[idx] = cnt
    used[cnt] = True
    cnt += 1

target = end.index(min(end))
for i in range(1, 2*N+1):
    if used[i]:
        continue
    if i < end[target]:
        print("NO")
        sys.exit()
    if ans[target]:
        ans[target].append((oppo(ans[target][-1][0]), "CHAIN", i))
        end[target] = i
    else:
        ans[target].append((oppo(query[target][0]), "CHAIN", i))
        end[target] = i

print("YES")
for i in range(M):
    print(*query[i])
    for chain in ans[i]:
        print(*chain)
