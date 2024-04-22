A = input()
B = input()
C = input()

dp = [[[0 for i in range(len(C)+1)] for j in range(len(B)+1)]
      for k in range(len(A)+1)]


# dp = [[0 for i in range(len(B)+1)] for j in range(len(A)+1)]

# for i in range(len(A)):
#     for j in range(len(B)):
#         if A[i] == B[j]:
#             dp[i+1][j+1] = dp[i][j] + 1
#         else:
#             dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j])

for i in range(len(A)):
    for j in range(len(B)):
        for k in range(len(C)):
            if A[i] == B[j] == C[k]:
                dp[i+1][j+1][k+1] = dp[i][j][k] + 1
            else:
                dp[i+1][j+1][k+1] = max(dp[i][j+1][k+1], dp[i+1]
                                        [j][k+1], dp[i+1][j+1][k])

print(dp[len(A)][len(B)][len(C)])
