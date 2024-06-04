import sys

input = sys.stdin.readline

N, M, K = map(int, input().split())
lst1 = []
for i in range(N):
    lst1.append(int(input()))
lst2 = []
for i in range(M):
    lst2.append(int(input()))

cnt = min(sum(lst1), sum(lst2))

ans = 0
cnt1 = 0
for i in range(N):
    if cnt1 + lst1[i] < cnt:
        cnt1 += lst1[i]
        ans += (i + 1) * lst1[i]
    else:
        ans += (cnt - cnt1) * (i + 1)
        break
cnt2 = 0
for i in range(M):
    if cnt2 + lst2[i] < cnt:
        cnt2 += lst2[i]
        ans += (i + 1) * lst2[i]
    else:
        ans += (cnt - cnt2) * (i + 1)
        break

print(cnt, ans)
