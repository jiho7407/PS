import sys
input = sys.stdin.readline
sys.setrecursionlimit(2000)

mx = 1001

N = int(input())
quest = [tuple(map(int, input().split())) for i in range(N)]

dp = [[-1]*mx for i in range(mx)] # dp[STR][INT], 어차피 퀘는 다 깨니까 PNT는 해당 dp상황에 대해 고정?인듯?
PNT = [[2]*mx for i in range(mx)] # 해당 상황 PNT
clear = [[0]*mx for i in range(mx)]

for i in range(1, mx):
    for j in range(1, mx):
        PNT[i][j] -= i+j
        for q in quest:
            if i >= q[0] or j >= q[1]:
                PNT[i][j] += q[2]
                clear[i][j] += 1

def solve(STR, INT):
    if dp[STR][INT] != -1:
        return dp[STR][INT]
    if STR >= 1000 or INT >= 1000:
        return clear[STR][INT]
    if PNT[STR][INT] == 0:
        return clear[STR][INT]
    dp[STR][INT] = max(solve(STR+1, INT), solve(STR, INT+1))
    return dp[STR][INT]

print(solve(1, 1))
