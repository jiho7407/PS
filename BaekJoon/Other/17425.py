import sys

mx = 1000001
cnt = [0] * mx
for i in range(1, mx):
    for j in range(i, mx, i):
        cnt[j] += i

print(cnt[:100])
for TC in range(int(input())):
    print(cnt[cnt[int(input())]])