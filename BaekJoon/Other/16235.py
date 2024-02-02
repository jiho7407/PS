import sys
from collections import deque
input = sys.stdin.readline

dx = [-1, -1, -1, 0, 0, 1, 1, 1]
dy = [-1, 0, 1, -1, 1, -1, 0, 1]

N, M, K = map(int, input().split())
Add = []
for i in range(N):
    Add.append([*map(int, input().split())])

board = [[deque() for i in range(N)] for j in range(N)]

for i in range(M):
    x, y, z = map(int, input().split())
    board[x-1][y-1].append(z)

nutr = [[5 for i in range(N)] for j in range(N)]

for Y in range(K):
    # 봄, 여름
    for i in range(N):
        for j in range(N):
            # board[i][j] = deque(sorted(board[i][j], key=lambda x: x))
            templ = len(board[i][j])
            tempd = 0
            for t in range(templ):
                if board[i][j][0] <= nutr[i][j]:
                    nutr[i][j] -= board[i][j][0]
                    board[i][j].rotate(-1)
                    board[i][j][-1] += 1
                else:
                    tempd += board[i][j].popleft()//2
            nutr[i][j] += tempd
    # 가을
    for i in range(N):
        for j in range(N):
            for tree in board[i][j]:
                if tree % 5:
                    continue
                for d in range(8):
                    px = i + dx[d]
                    py = j + dy[d]
                    if px < 0 or px >= N or py < 0 or py >= N:
                        continue
                    board[px][py].appendleft(1)
    # 겨울
    for i in range(N):
        for j in range(N):
            nutr[i][j] += Add[i][j]

ans = 0
for i in range(N):
    for j in range(N):
        ans += len(board[i][j])
print(ans)


# import sys
# input = sys.stdin.readline

# dx = [-1, -1, -1, 0, 0, 1, 1, 1]
# dy = [-1, 0, 1, -1, 1, -1, 0, 1]

# N, M, K = map(int, input().split())
# Add = []
# for i in range(N):
#     Add.append([*map(int, input().split())])

# board = [[[] for i in range(N)] for j in range(N)]

# for i in range(M):
#     x, y, z = map(int, input().split())
#     board[x-1][y-1].append(z)

# nutr = [[5 for i in range(N)] for j in range(N)]

# for Y in range(K):
#     # 봄, 여름
#     for i in range(N):
#         for j in range(N):
#             templst = []
#             deadlst = []
#             board[i][j].sort()
#             for tree in board[i][j]:
#                 if tree <= nutr[i][j]:
#                     templst.append(tree+1)
#                     nutr[i][j] -= tree
#                 else:
#                     deadlst.append(tree//2)
#             board[i][j] = templst
#             nutr[i][j] += sum(deadlst)
#     # 가을
#     for i in range(N):
#         for j in range(N):
#             for tree in board[i][j]:
#                 if tree % 5:
#                     continue
#                 for d in range(8):
#                     px = i + dx[d]
#                     py = j + dy[d]
#                     if px < 0 or px >= N or py < 0 or py >= N:
#                         continue
#                     board[px][py].append(1)
#     # 겨울
#     for i in range(N):
#         for j in range(N):
#             nutr[i][j] += Add[i][j]

#     print()
#     for i in range(N):
#         print(board[i])
#     print()
#     for i in range(N):
#         print(nutr[i])

# ans = 0
# for i in range(N):
#     for j in range(N):
#         ans += len(board[i][j])
# print(ans)
