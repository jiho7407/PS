import sys
input = sys.stdin.readline

N = int(input())
trees = [*map(int, input().split())]

sum = 0
odds = 0
for i in range(N):
    sum += trees[i]
    if trees[i] % 2 == 1:
        odds += 1

if sum % 3 != 0:
    print("NO")
elif sum//3 < odds:
    print("NO")
else:
    print("YES")
