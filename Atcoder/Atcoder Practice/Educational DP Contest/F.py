A = input()
B = input()

dp = [[0] * (len(B)+1) for i in range(len(A)+1)]

for i in range(len(A)):
    for j in range(len(B)):
        if A[i] == B[j]:
            dp[i+1][j+1] = dp[i][j]+1
            continue
        dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j])

ans = ""

x, y = len(A), len(B)

cmd = dp[-1][-1]

while True:
    if cmd == 0:
        break
    if dp[x-1][y] == cmd:
        x -= 1
    elif dp[x][y-1] == cmd:
        y -= 1
    else:
        ans += A[x-1]
        x -= 1
        y -= 1
        cmd -= 1

print(''.join(reversed(ans)))