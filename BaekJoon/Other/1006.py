import sys
import copy
# input = sys.stdin.readline

def solve(enemy):
    # 1 - N, N+1*2N 연결 존재 X
    dp = [0] * N
    status = [0] * N # 0 : 둘다 한개, 1: 위만 두개, 2: 아래만 두개, 3: 둘다 두개 블럭

    if enemy[0][0] + enemy[1][0] <= W:
        dp[0] = 1
        status[0] = 3
    else:
        dp[0] = 2
        status[0] = 0

    for i in range(1, N):
        s1 = enemy[0][i-1] + enemy[0][i] <= W
        s2 = enemy[1][i-1] + enemy[1][i] <= W
        s3 = enemy[0][i] + enemy[1][i] <= W
        if status[i-1] == 0:
            if (s1 and s2):
                dp[i] = dp[i-1]
                status[i] = 3
            elif s1:
                dp[i] = dp[i-1]+1
                status[i] = 1
            elif s2:
                dp[i] = dp[i-1]+1
                status[i] = 2
            elif s3:
                dp[i] = dp[i-1]+1
                status[i] = 3
            else:
                dp[i] = dp[i-1]+2
                status[i] = 0
        elif status[i-1] == 1:
            if s2:
                dp[i] = dp[i-1]+1
                status[i] = 2
            elif s3:
                dp[i] = dp[i-1]+1
                status[i] = 3
            else:
                dp[i] = dp[i-1]+2
                status[i] = 0
        elif status[i-1] == 2:
            if s1:
                dp[i] = dp[i-1]+1
                status[i] = 1
            elif s3:
                dp[i] = dp[i-1]+1
                status[i] = 3
            else:
                dp[i] = dp[i-1]+2
                status[i] = 0
        elif status[i-1] == 3:
            if s3:
                dp[i] = dp[i-1]+1
                status[i] = 3
            else:
                dp[i] = dp[i-1]+2
                status[i] = 0
        if s1 and s2 and dp[i] > dp[i-2]+2:
            dp[i] = dp[i-2]+2
            status[i] = 3
    return dp[-1]

for TC in range(int(input())):
    N, W = map(int, input().split())
    oenemy = []
    for i in range(2):
        oenemy.append([*map(int, input().split())])

    if N == 1:
        if oenemy[0][0] + oenemy[1][0] <= W:
            print(1)
        else:
            print(2)
        continue

    ans = int(1e10)

    IC = (oenemy[0][0] + oenemy[0][N-1] <= W)
    OC = (oenemy[1][0] + oenemy[1][N-1] <= W)

    enemy = copy.deepcopy(oenemy)
    ans = min(ans, solve(enemy))

    if IC:
        enemy = copy.deepcopy(oenemy)
        enemy[0][0] = W
        enemy[0][N-1] = W
        ans = min(ans, solve(enemy)-1)
    if OC:
        enemy = copy.deepcopy(oenemy)
        enemy[1][0] = W
        enemy[1][N-1] = W
        ans = min(ans, solve(enemy)-1)
    if IC and OC:
        enemy = copy.deepcopy(oenemy)
        enemy[0][0] = W
        enemy[0][N-1] = W
        enemy[1][0] = W
        enemy[1][N-1] = W
        ans = min(ans, solve(enemy)-2)
    print(ans)
        