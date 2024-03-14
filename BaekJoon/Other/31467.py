import sys

input = sys.stdin.readline
sys.setrecursionlimit(int(1e6) + 100)

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

N = int(input())
board = []
for i in range(N):
    board.append(input().rstrip())

visit = [[0] * N for i in range(N)]
cnt = 1

isAP = [[False] * N for i in range(N)]
V = 0
E = 0


def dfs(cur, root):
    global cnt
    global V, E
    cx, cy = cur
    visit[cx][cy] = cnt
    cnt += 1
    V += 1

    temp = visit[cx][cy]
    deg = 0
    for d in range(4):
        px = cx + dx[d]
        py = cy + dy[d]
        if px < 0 or px >= N or py < 0 or py >= N:
            continue
        if board[px][py] == ".":
            continue

        E += 1
        if visit[px][py]:
            temp = min(temp, visit[px][py])
        else:
            deg += 1
            sub = dfs((px, py), False)
            if not root and sub >= visit[cx][cy]:
                isAP[cx][cy] = True
            temp = min(temp, sub)
    if root and deg >= 2:
        isAP[cx][cy] = True
    return temp


for i in range(N):
    for j in range(N):
        if board[i][j] == ".":
            continue
        if visit[i][j]:
            continue
        dfs((i, j), True)

# for i in range(N):
#     print(isAP[i])
# print(V, E)

E //= 2
ans = []
for i in range(N):
    for j in range(N):
        if board[i][j] == ".":
            continue
        if isAP[i][j]:
            continue
        deg = 0
        for d in range(4):
            px = i + dx[d]
            py = j + dy[d]
            if px < 0 or px >= N or py < 0 or py >= N:
                continue
            if board[px][py] == ".":
                continue
            deg += 1
        if E - deg == V - 2:
            ans.append((i + 1, j + 1))

print(len(ans))
for an in ans:
    print(*an)
