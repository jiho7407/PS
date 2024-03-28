import sys
input = sys.stdin.readline


def btr(cur, state, cnt):
    temp = cnt
    for goal in range(N):
        if not OK[cur][goal]:
            continue
        if state & (1 << goal):
            continue
        temp = max(temp, btr(goal, state | (1 << goal), cnt+1))
    return temp


for TC in range(int(input())):
    N = int(input())
    lst = []
    for i in range(N):
        a, b = map(str, input().split())
        lst.append((a, b))

    root = [i for i in range(N)]

    OK = [[False for i in range(N)] for j in range(N)]
    for i in range(N):
        for j in range(N):
            if lst[i][0] == lst[j][0] or lst[i][1] == lst[j][1]:
                OK[i][j] = True

    dp = [[0] * (1 << N) for i in range(N)]
    for i in range(N):
        dp[i][1 << i] = 1
    for state in range(1 << N):
        for cur in range(N):
            if not state & (1 << cur):
                continue
            for goal in range(N):
                if state & (1 << goal) or not OK[cur][goal]:
                    continue
                dp[goal][state | (1 << goal)] = max(
                    dp[goal][state | (1 << goal)], dp[cur][state] + 1)

    mx = max(max(row) for row in dp)
    print(N-mx)
