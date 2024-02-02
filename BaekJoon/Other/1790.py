N, K = map(int, input().split())


def Ncalc(N, K):
    Nlen = len(str(N))
    strlen = 0
    for i in range(1, Nlen):
        strlen += 9 * i * (10**(i-1))
    left = K - strlen
    cur = (10**(Nlen-1))
    if left > Nlen*(N-cur):
        return False
    else:
        return True


def nums(N, K):
    K = K
    curlen = 1
    while True:
        temp = 9 * curlen * (10**(curlen-1))
        if K > temp:
            K -= temp
            curlen += 1
        else:
            break
    K -= 1
    curnum = K // curlen + 10**(curlen-1)
    curidx = K % curlen
    return str(curnum)[curidx]


if Ncalc(N+1, K):
    print(nums(N+1, K))
else:
    print(-1)
