S = input()

mx = 0
for i in range(1, len(S)//2):
    if S[:i] == S[i:2*i]:
        mx = 2*i
print(mx)
