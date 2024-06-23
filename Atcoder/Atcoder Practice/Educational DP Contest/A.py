N = int(input())
lst = [*map(int, input().split())]
dp = [0, abs(lst[1] - lst[0])]
for i in range(2, N):
    dp.append(min(dp[-1] + abs(lst[i] - lst[i-1]), dp[-2] + abs(lst[i] - lst[i-2])))

print(dp[-1])