import sys
input = sys.stdin.readline

for TC in range(int(input())):
    F, R, N = map(int, input().split())
    office = [[0] for i in range(F)]
    for i in range(N):
        r, c = map(int, input().split())
        office[r-1].append(c)
    ans = 2*F + R + 1
    for i in range(F):
        temp = 100000
        office[i] += [R+1]
        office[i].sort()
        for j in range(len(office[i])-1):
            temp = min(temp, office[i][j] + R + 1 - office[i][j+1])
        ans += temp*2
    print(ans)
