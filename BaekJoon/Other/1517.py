import sys
input = sys.stdin.readline

N = int(input())
templst = [*map(int, input().split())]
lst = []
tree = [0 for i in range(2*N)]

for idx, num in enumerate(templst, start=1):
    lst.append([idx, num])

lst.sort(key=lambda x: x[1])

ans = 0
for num, value in lst:
    a = N+num-1
    b = 2*N
    while a < b:
        if a % 2:
            ans += tree[a]
            a += 1
        if b % 2:
            b -= 1
            ans += tree[b]
        b //= 2
        a //= 2
    idx = N+num-1
    while idx >= 1:
        tree[idx] += 1
        idx //= 2
print(ans)
