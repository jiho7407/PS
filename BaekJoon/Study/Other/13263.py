import sys
input = sys.stdin.readline

def intersect(tup1, tup2):
    a1, b1 = tup1
    a2, b2 = tup2
    if a1 < a2:
        a1, a2 = a2, a1
        b1, b2 = b2, b1
    return (b2-b1)/(a1-a2)

N = int(input())
A = [*map(int, input().split())]
B = [*map(int, input().split())]
dp = [0]

line = []
line.append((B[0], 0, 0)) # (a, b, c) -> ax + b, x >= c

for i in range(1, N):
    s, e = 0, len(line)-1
    while s<=e:
        m = (s+e)//2
        if line[m][2] > A[i]:
            e = m-1
        else:
            cur = m
            s = m+1
    dp.append(line[cur][0]*A[i] + line[cur][1])
    while len(line) > 1 and intersect((line[-1][0], line[-1][1]), (B[i], dp[i])) < line[-1][2]:
        line.pop()
    line.append((B[i], dp[i], intersect((line[-1][0], line[-1][1]), (B[i], dp[i]))))
    # print(line, dp)

print(dp[-1])