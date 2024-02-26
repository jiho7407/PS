def kmp_preprocess(t):
    m = len(t)
    fail = [0] * m
    j = 0
    for i in range(1, m):
        while j > 0 and t[i] != t[j]:
            j = fail[j-1]
        if t[i] == t[j]:
            j += 1
        fail[i] = j
    return fail


def min_removals(s, t):
    n, m = len(s), len(t)
    fail = kmp_preprocess(t)
    f = [[-1 for _ in range(m)] for _ in range(2)]
    tmp = 0
    f[tmp][0] = 0
    ans = 0

    for i in range(n):
        f[tmp ^ 1] = [-1] * m
        for j in range(m):
            if f[tmp][j] != -1:
                f[tmp ^ 1][j] = max(f[tmp ^ 1][j], f[tmp][j])
                k = j
                while k > 0 and s[i] != t[k]:
                    k = fail[k-1]
                if s[i] == t[k]:
                    k += 1
                if k < m:
                    f[tmp ^ 1][k] = max(f[tmp ^ 1][k], f[tmp][j] + 1)
        tmp ^= 1

    for i in range(m):
        ans = max(ans, f[tmp][i])

    return n - ans


# 입력 받기
s = input("Bessie's initial necklace: ")
t = input("The other cow's name: ")

# 결과 출력
print("Minimum number of stones to be removed: ", min_removals(s, t))
