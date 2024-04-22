import sys
input = sys.stdin.readline
sys.setrecursionlimit(int(1e6))

N = int(input())
links = [[] for i in range(N+1)]
for i in range(N-1):
    x, y = map(int, input().split())
    links[x].append(y)
    links[y].append(x)

nodecnt = [0] * (N+1)
def makenodecnt(i, parent):
    temp = 1
    for goal in links[i]:
        if goal == parent:
            continue
        temp += makenodecnt(goal, i)
    nodecnt[i] = temp
    return temp

makenodecnt(1, 0)

for i in range(1, N+1):
    temp = 2 * (N-1)

    tempsum = N - nodecnt[i]
    sqsum = tempsum**2

    for goal in links[i]:
        if nodecnt[goal] > nodecnt[i]:
            continue
        tempsum += nodecnt[goal]
        sqsum += nodecnt[goal]**2
    
    temp += tempsum**2 - sqsum

    print(temp)