import sys

input = sys.stdin.readline

N = int(input())
animals = []
for _ in range(N):
    lst = list(input().split())
    animals.append(set(lst[2:]))

ans = 0
for i in range(N - 1):
    for j in range(i + 1, N):
        ans = max(ans, len(animals[i] & animals[j]))
print(ans + 1)
