import sys
input = sys.stdin.readline

a, b, c = map(int, input().split())
for i in range(a, b+1, c):
    print(i, end=" ")