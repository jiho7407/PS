N, K = map(int, input().split())
lst = [*map(int, input().split())]
dp = [0, abs(lst[1] - lst[0])]
for i in range(2, N):
    temp = int(1e10)
    for j in range(1, K+1):
        if i-j <0:
            break
        temp = min(temp, dp[-j] + abs(lst[i] - lst[i-j]))
    dp.append(temp)

print(dp[-1])