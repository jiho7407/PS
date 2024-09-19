N = int(input())

S = [0]
for i in range(1, 1000):
    s = str(i)
    S.append(S[-1]+len(s))

N = str(N)
ans = []
for i in range(min(len(N), 3)):
    for j in range(min(len(N), 3)):
        front = N[:i+1]
        back = N[-(j+1):]
        if back[0] == "0":
            continue
        if (S[int(back)] - S[int(front)-1]) == len(N):
            ans.append((front, back))

print(*ans[0])