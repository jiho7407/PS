import sys
input = sys.stdin.readline

N = int(input())
B = bin(N)

ans = 0
for i in range(len(B)-1, -1, -1):
    if B[i] != "0":
        break
    ans += 1
print(ans)
