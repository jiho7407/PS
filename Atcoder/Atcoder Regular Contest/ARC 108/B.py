import sys
input = sys.stdin.readline
# sys.setrecursionlimit(10**6)

N = int(input())
S = input().rstrip()

stk = []
for i in range(N):
    cmd = S[i]
    stk.append(cmd)
    while len(stk) >= 3:
        if stk[-3:] == list("fox"):
            stk.pop()
            stk.pop()
            stk.pop()
        else:
            break
print(len(stk))
