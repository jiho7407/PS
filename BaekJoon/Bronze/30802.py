N = int(input())
size = [*map(int, input().split())]
T, P = map(int, input().split())

ans = 0
for sz in size:
    ans += (sz-1)//T + 1
print(ans)
print(N//P, N % P)
