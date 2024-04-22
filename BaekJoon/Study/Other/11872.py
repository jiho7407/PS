import sys
input = sys.stdin.readline

N = int(input())
lst = [*map(int, input().split())]

ans = 0
for cmd in lst:
    if cmd % 4 == 3:
        cmd += 1
    elif cmd % 4 == 0:
        cmd -= 1
    ans ^= cmd

if ans == 0:
    print("cubelover")
else:
    print("koosaga")


# def mex(mex_set):
#     i = 0
#     while i in mex_set:
#         i += 1
#     return i
# dp = [0, 1]
# for i in range(2, 101):
#     tempset = set()
#     for j in range(i):
#         tempset.add(dp[j])
#     for j in range(1, i//2+1):
#         tempset.add(dp[j] ^ dp[i-j])
#     dp.append(mex(tempset))
# print(dp)
# [1, 2, 4, 3] , [5, 6, 8, 7] ...
