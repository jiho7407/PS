import sys
import copy
from collections import deque
input = sys.stdin.readline

dx = [0, -1, -1, -1, 0, 1, 1, 1]
dy = [-1, -1, 0, 1, 1, 1, 0, -1]

sdx = [-1, 0, 1, 0]
sdy = [0, -1, 0, 1]

fish = [[[] for i in range(4)] for j in range(4)]
smell = [[0 for i in range(4)] for j in range(4)]
M, S = map(int, input().split())
for i in range(M):
    x, y, d = map(int, input().split())
    fish[x-1][y-1].append(d-1)

sx, sy = map(int, input().split())
sx -= 1
sy -= 1


for TC in range(S):
    # 1. 복제한다
    newfish = [[[] for i in range(4)] for j in range(4)]
    
    # 2. 물고기가 이동한다
    for i in range(4):
        for j in range(4):
            for idx in range(len(fish[i][j])):
                d = fish[i][j][idx]
                moved = False
                for _ in range(8):
                    pd = (d - _)%8
                    px = i + dx[pd]
                    py = j + dy[pd]
                    if px<0 or px>=4 or py<0 or py>=4:
                        continue
                    if smell[px][py]:
                        continue
                    if px == sx and py == sy:
                        continue
                    moved = True
                    newfish[px][py].append(pd)
                    break
                if not moved:
                    newfish[i][j].append(d)

    # 3. 상어가 이동한다
    mxmove = []
    mx = -1
    for i in range(64):
        visited = set()
        eat = 0
        a, b, c = (i>>4)&3, (i>>2)&3, i&3
        move = [a, b, c]
        movable = True
        px = sx
        py = sy
        for d in move:
            px += sdx[d]
            py += sdy[d]
            if px<0 or px>=4 or py<0 or py>=4:
                movable = False
                break
            if not (px, py) in visited:
                eat += len(newfish[px][py])
            visited.add((px, py))
        if not movable:
            continue
        if eat > mx:
            mxmove = move
            mx = eat

    for d in mxmove:
        sx += sdx[d]
        sy += sdy[d]
        if newfish[sx][sy]:
            smell[sx][sy] = 3
            newfish[sx][sy] = []
            
    # 4. 냄새가 사라진다
    for i in range(4):
        for j in range(4):
            if smell[i][j]:
                smell[i][j] -= 1
        
    # 5. 복제가 완료된다
    for i in range(4):
        for j in range(4):
            fish[i][j] += newfish[i][j]

ans = 0
for i in range(4):
    for j in range(4):
        ans += len(fish[i][j])
print(ans)