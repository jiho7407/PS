import sys
input = sys.stdin.readline

N = int(input())
lst = [*map(int, input().split())]
lst.sort()
ans = 0
ans += sum(lst[N//2:])

ans *= 2
if N % 2:
    ans -= lst[N//2]

print(ans)
