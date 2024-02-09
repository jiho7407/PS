import sys
input = sys.stdin.readline

for TC in range(int(input())):
    N, W = map(int, input().split())
    enemy = []
    for i in range(2):
        enemy.append([*map(int, input().split())])
    
    # 1 - N, N+1*2N 연결 존재 X
    dp = [0] * (N+1)

    if enemy[0][0] + enemy[1][0] <= W:
        dp[1] = 1
    else:
        dp[1] = 2
    for i in range(1, N):
        mn = 100
        # 가로로 들어가는 경우
        temp = 0
        if enemy[0][i-1] + enemy[0][i] <= W:
            temp += 1
        else:
            temp += 2
        if enemy[1][i-1] + enemy[1][i] <= W:
            temp += 1
        else:
            temp += 2
        mn = min(mn, temp)

        # 세로로 들어가는 경우
        temp = 0
        if enemy[0][i-1] + enemy[1][i-1] <= W:
            temp += 1
        else:
            temp += 2
        if enemy[0][i] + enemy[1][i] <= W:
            temp += 1
        else:
            temp += 2
        mn = min(mn, temp)
        dp[i+1] = dp[i-1] + mn
    print(dp)

    IC = (enemy[0][0] + enemy[0][N-1] <= W)
    OC = (enemy[0][0] + enemy[0][N-1] <= W)

    # 1 - N 연결
    dp2 = [0] * (N+1)

    dp2[1] = 2

    for i in range(1, N):
        mn = 100
        # 가로로 들어가는 경우
        temp = 0
        if enemy[0][i-1] + enemy[0][i] <= W:
            temp += 1
        else:
            temp += 2
        if enemy[1][i-1] + enemy[1][i] <= W:
            temp += 1
        else:
            temp += 2
        mn = min(mn, temp)

        # 세로로 들어가는 경우
        temp = 0
        if enemy[0][i-1] + enemy[1][i-1] <= W:
            temp += 1
        else:
            temp += 2
        if enemy[0][i] + enemy[1][i] <= W:
            temp += 1
        else:
            temp += 2
        mn = min(mn, temp)
        dp[i+1] = dp[i-1] + mn
    print(dp)
