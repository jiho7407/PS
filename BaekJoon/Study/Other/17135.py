import sys
from collections import deque
from itertools import combinations
import copy
input = sys.stdin.readline

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
N, M, D = map(int, input().split())
originboard = []
for i in range(N):
    originboard.append([*map(int, input().split())])


def printer():
    for i in range(N):
        print(board[i])


def findEnemy(a, board):
    visited = [[False for j in range(M)]for i in range(N)]
    possiblelst = []
    Q = deque()
    Q.append(((N-1, a), 1))
    if board[N-1][a] == 1:
        return (N-1, a)
    while Q:
        (curx, cury), dist = Q.popleft()
        if dist >= D:
            continue
        for d in range(4):
            px = curx + dx[d]
            py = cury + dy[d]
            if px < 0 or px >= N or py < 0 or py >= M:
                continue
            if visited[px][py]:
                continue
            if board[px][py] == 1:
                possiblelst.append([px, py, dist+1])
            if possiblelst and possiblelst[0][2] < dist:
                continue
            Q.append(((px, py), dist+1))
    possiblelst.sort(key=lambda x: (x[2], x[1]))
    if possiblelst:
        return (possiblelst[0][0], possiblelst[0][1])
    return False


nums = [i for i in range(M)]
archers = list(combinations(nums, 3))
ans = 0
for i in range(len(archers)):
    board = copy.deepcopy(originboard)
    board = deque(board)
    cnt = 0
    for j in range(N):
        enemyset = set()
        for archer in archers[i]:
            temp = findEnemy(archer, board)
            if temp:
                enemyset.add(temp)
        cnt += len(enemyset)
        if enemyset:
            for x, y in enemyset:
                board[x][y] = 0
        board.pop()
        board.appendleft([0 for i in range(M)])
    ans = max(ans, cnt)
print(ans)
