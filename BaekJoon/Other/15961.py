import sys
input = sys.stdin.readline

N, d, k, c = map(int, input().split())
lst = []
for i in range(N):
    lst.append(int(input()))
ans = 0
sushilst = [0 for i in range(d+1)]


def calcsushi(templst):
    tempcnt = 0
    for sushi in templst:
        if sushi:
            tempcnt += 1
    return tempcnt


sushilst[c] += 1
for i in range(k):
    sushilst[lst[i]] += 1
tempans = calcsushi(sushilst)

for i in range(N):
    sushilst[lst[i]] -= 1
    if sushilst[lst[i]] == 0:
        tempans -= 1
    temp = i+k
    if temp >= N:
        temp %= N
    sushilst[lst[temp]] += 1
    if sushilst[lst[temp]] == 1:
        tempans += 1
    ans = max(ans, tempans)
print(ans)
