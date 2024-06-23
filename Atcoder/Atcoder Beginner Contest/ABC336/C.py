import sys
input = sys.stdin.readline

lst = ["0", "2", "4", "6", "8"]
N = int(input())-1

ans = ""
ans += lst[N % 5]
N //= 5
while N > 0:
    ans += lst[N % 5]
    N //= 5
for i in range(len(ans)-1, -1, -1):
    print(ans[i], end="")
print()
