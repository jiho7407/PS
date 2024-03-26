N = int(input())
sx, sy, ex, ey = map(int, input().split())


def calc(p1, p2):
    ax, ay = p1
    bx, by = p2
    return abs(ax-bx) + abs(ay-by)


mn = int(1e18)
ans = 0
for i in range(N):
    M = int(input())
    lst = []
    for j in range(M):
        lst.append(tuple(map(int, input().split())))
    temp = 0

    temp += calc((sx, sy), lst[0])
    temp += calc((ex, ey), lst[-1])
    for j in range(M-1):
        temp += calc(lst[j], lst[j+1])
    if temp < mn:
        mn = temp
        ans = i+1
print(ans)
