K, N = map(int, input().split())

lsts = [[1] for i in range(K)]
p = [1, 2003, 2011, 2017, 2027, 2029, 2039, 2053, 2063, 2069, 2081, 2083, 2087, 2089, 2099, 2111, 2113, 2129, 2131, 2137, 2141, 2143, 2153, 2161, 2179, 2203, 2207, 2213, 2221, 2237, 2239]

for i in range(K):
    for j in range(1, N):
        lsts[i].append(lsts[i][-1]+(p[i]))

for i in range(K):
    print(*lsts[i][:N])