import itertools


t = 5
print(t)
ps = [2, 3, 5, 7, 11, 13, 17, 19, 23]
best = (0, 0)


def rec(i, prod, divs, used):
    global best
    cur = 0
    best = max(best, (divs, prod, used))
    if i == len(ps):
        return
    while prod <= 10**9:
        rec(i+1, prod, divs*(cur+1), used + [cur])
        cur += 1
        prod *= ps[i]


rec(0, 1, 1, [])
# print(best)
# exit(0)
for i in range(t):
    n = 100000
    prod = best[1]

    a = [prod]*n
    b = [prod]*n
    l = len(ps)
    at = 1
    for i in list(itertools.product(*[range(i+1) for i in best[2]]))[::-1]:
        res = 1
        for w, k in enumerate(i):
            res *= ps[w]**k
        b[at*50] = res
        at += 1
    print(n)
    print(*a)
    print(*b)
