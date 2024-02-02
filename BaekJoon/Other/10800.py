import sys
import bisect
input = sys.stdin.readline

N = int(input())

alllst = []
colorlst = [[] for i in range(N+1)]
balls = []

for i in range(N):
    color, size = map(int, input().split())
    balls.append((color, size))
    alllst.append(size)
    colorlst[color].append(size)

alllst.sort()
for minilst in colorlst:
    minilst.sort()

sumlst = [alllst[0]]
for i in range(1, N):
    sumlst.append(sumlst[-1] + alllst[i])

colorsumlst = [[] for i in range(N+1)]
for i in range(1, N+1):
    if colorlst[i]:
        colorsumlst[i].append(colorlst[i][0])
        for j in range(1, len(colorlst[i])):
            colorsumlst[i].append(colorsumlst[i][-1] + colorlst[i][j])

for color, size in balls:
    temp = bisect.bisect_left(alllst, size)-1
    if temp == -1:
        print(0)
        continue
    ans = sumlst[temp]
    temp = bisect.bisect_left(colorlst[color], size)-1
    if temp == -1:
        print(ans)
        continue
    ans -= colorsumlst[color][temp]
    print(ans)
