import sys
import heapq
import copy
input = sys.stdin.readline

N = int(input())
lst = [*map(int, input().split())]
M = int(input())
moves = []
for i in range(M):
    l, r, c = map(int, input().split())
    l -= 1
    r -= 1
    moves.append((l, r, c))
moves.sort(key = lambda x: x[2])

dist = dict()
dist[tuple(lst)] = 0

pq = []
heapq.heappush(pq, (0, lst))

def act(actlst, _move):
    _actlst = copy.deepcopy(actlst)
    l, r, c = _move
    _actlst[l], _actlst[r] = _actlst[r], _actlst[l]
    return _actlst

answered = False
while pq:
    curdist, curlst = heapq.heappop(pq)
    suc = True
    for i in range(N-1):
        if curlst[i] > curlst[i+1]:
            suc = False
    if suc:
        print(curdist)
        answered = True
        break

    if tuple(curlst) in dist and dist[tuple(curlst)] < curdist:
        continue
    
    for move in moves:
        newlst = act(curlst, move)
        if tuple(newlst) not in dist or curdist + move[2] < dist[tuple(newlst)]:
            dist[tuple(newlst)] = curdist + move[2]
            heapq.heappush(pq, (curdist+move[2], newlst))

if not answered:
    print(-1)