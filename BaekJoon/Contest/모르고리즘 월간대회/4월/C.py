N, K = map(int, input().split())


def reverse(S):
    T = ""
    for i in range(len(S) - 1, -1, -1):
        T += S[i]
    return T


def convert(N, d):
    S = ""
    while N:
        S += str(N % d)
        N //= d
    return reverse(S)


S = convert(N, K)

lst = S.split("0")

sm = 0
for a in lst:
    if not a:
        continue
    sm += int(a)

print(convert(sm, K))
