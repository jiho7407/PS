N = int(input())
lst = [*map(int, input().split())]

ans = 0
cur = 0
for i in range(N):
    if lst[i] == 0:
        if i > 0 and lst[i-1] == 0:
            ans = max(ans, cur)
            cur = 0
        continue
    cur += 1

print(max(cur, ans))
