import sys
input = sys.stdin.readline

N = int(input())
lst = [*map(int, input().split())]
for i in range(N):
    if lst[i] > lst[0]:
        print(i+1)
        sys.exit()
print(-1)
