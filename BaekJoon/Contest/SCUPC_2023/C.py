import sys
input = sys.stdin.readline

N = int(input())
lst = [*map(int, input().split())]
lst.sort()

lst2 = []
for i in range(N-1):
    lst2.append(lst[i+1] - lst[i])

temp = 0
for i in range(1, len(lst2), 2):
    temp += lst2[i]
temp += lst2[0]
ans = temp
for i in range(1, N-3, 2):
    temp += lst2[i+1] - lst2[i]
    ans = min(ans, temp)
print(ans)
