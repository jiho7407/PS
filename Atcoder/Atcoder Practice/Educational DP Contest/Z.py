N, C = map(int, input().split())
lst = [*map(int, input().split())]
dp = [0, (lst[1] - lst[0])**2+C]
for i in range(2, N):
    temp = int(1e10)
    for j in range(1, i+1):
        temp = min(temp, dp[-j] + (lst[i] - lst[i-j])**2+C)
    dp.append(temp)

print(dp[-1])