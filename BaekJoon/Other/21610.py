import sys
input = sys.stdin.readline

dx = [0, -1, -1, -1, 0, 1, 1, 1]
dy = [-1, -1, 0, 1, 1, 1, 0, -1]

cx = [-1, -1, 1, 1]
cy = [-1, 1, -1, 1]

N, M = map(int, input().split())
board = []
for i in range(N):
    board.append([*map(int, input().split())])

clouds = [[N-1, 0], [N-1, 1], [N-2, 0], [N-2, 1]]
for i in range(M):
    cloudset = set()
    di, si = map(int, input().split())
    for cloud in clouds:
        cloud[0] += si * dx[di-1]
        cloud[1] += si * dy[di-1]
        cloud[0] %= N
        cloud[1] %= N
        cloudset.add(tuple(cloud))
    for cloud in clouds:
        x, y = cloud
        board[x][y] += 1

    for cloud in clouds:
        x, y = cloud
        temp = 0
        for c in range(4):
            px = x+cx[c]
            py = y+cy[c]
            if px < 0 or px >= N or py < 0 or py >= N:
                continue
            if board[px][py]:
                board[x][y] += 1

    tempcloud = []
    for j in range(N):
        for k in range(N):
            if (j, k) in cloudset:
                continue
            if board[j][k] >= 2:
                tempcloud.append([j, k])
                board[j][k] -= 2
    clouds = tempcloud

ans = 0
for i in range(N):
    ans += sum(board[i])
print(ans)
