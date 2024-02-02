S = input().split("><")

if len(S) > 1:
    S[0] += ">"
    S[-1] += "<"
    for i in range(1, len(S)-1):
        S[i] = "<" + S[i] + ">"

ans = 0
for cmd in S:
    a = cmd.count("<")
    b = cmd.count(">")

    if a > b:
        a, b = b, a

    ans += a*(a-1)//2
    ans += b*(b+1)//2

print(ans)
