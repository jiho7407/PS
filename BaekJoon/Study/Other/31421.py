import sys
input = sys.stdin.readline

N = int(input())
S = input().rstrip()

lst = []
cnt = 0
for i in range(N-1):
    if S[i] != S[i+1]:
        lst.append(i+1)
        cnt += 1

if cnt == 0:
    if S[0] == "W":
        print(0)
    else:
        print(-1)
elif cnt == 1:
    if S[0] == "W":
        print(-1)
    else:
        print(1)
        print(lst[0])
else:
    print(cnt)
    if S[0] == "W":
        lst[0], lst[1] = lst[1], lst[0]
    for i in range(1, cnt+1):
        print(lst[cnt-i])
