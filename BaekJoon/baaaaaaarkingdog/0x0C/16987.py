import sys
input = sys.stdin.readline

n = int(input())
egglst = []
for i in range(n):
    egglst.append([*map(int,input().split())])

ans = 0

def btr(i):
    global ans
    if i==n:
        # print(egglst)
        temp = 0
        for _ in range(n):
            if egglst[_][0] <= 0:
                temp+=1
        # print("답은", ans, temp)
        ans = max(ans, temp)
        return
    if egglst[i][0]<=0:
        btr(i+1)
        return
    hitted = False
    for j in range(n):
        if i == j or egglst[j][0]<=0:
            continue
        egglst[i][0] -= egglst[j][1]
        egglst[j][0] -= egglst[i][1]
        # print(i, j)
        btr(i+1)
        egglst[i][0] += egglst[j][1]
        egglst[j][0] += egglst[i][1]
        hitted = True
    if not hitted:
        btr(i+1)

btr(0)
print(ans)