import sys
input = sys.stdin.readline

N, A, B = map(int, input().split())
lst = [*map(int, input().split())]

rests = [0] * (N)
for i in range(N):
    rests[i] = lst[i] % (A + B)

restset = set(rests)
lst = sorted(list(restset))

ans = lst[-1] - lst[0]
for i in range(1, len(lst)):
    ans = min(ans, (A+B) + lst[i-1] - lst[i])

if ans < A:
    print("Yes")
else:
    print("No")
