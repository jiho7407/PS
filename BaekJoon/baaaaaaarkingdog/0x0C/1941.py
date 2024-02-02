import sys
from collections import deque
input = sys.stdin.readline

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
board = []
ans = 0

for i in range(5):
    board.append(list(input().rstrip()))

def bfs(bfslst):
    numy = 0
    for i in bfslst:
        if board[(i-1)//5][(i-1)%5] == "Y":
            numy += 1
    if numy >= 4:
        return
    princessmap = [[0 for i in range(5)] for i in range(5)]
    for i in bfslst:
        princessmap[(i-1)//5][(i-1)%5] = 1
    Q = deque()
    Q.append([(bfslst[0]-1)//5, (bfslst[0]-1)%5])
    princessmap[(bfslst[0]-1)//5][(bfslst[0]-1)%5] = 2
    area = 1
    while Q:
        curx, cury = Q.popleft()
        for d in range(4):
            px = curx + dx[d]
            py = cury + dy[d]
            if(px<0 or px>=5 or py<0 or py>=5): continue
            if princessmap[px][py] == 1:
                princessmap[px][py] = 2
                area += 1
                Q.append([px, py])
    if area == 7:
        global ans
        ans += 1
    return

templst = []
def btr(n, a):
    if a == 7:
        bfs(templst)
        return
    for i in range(n, 26):
        templst.append(i)
        btr(i+1, a+1)
        templst.pop()

for i in range(1, 20):
    templst.append(i)
    btr(i+1, 1)
    templst.pop()
print(ans)