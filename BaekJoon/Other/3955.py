import sys

def gcd(a, b):
    while b:
        r = a%b
        a = b
        b = r
    return a

def extgcd(a, b):
    ca = (1, 0)
    cb = (0, 1)
    while b:
        q, r = divmod(a, b)

        a, b = b, r
        
        cr = (ca[0] - q*cb[0], ca[1] - q*cb[1])
        ca, cb = cb, cr

    return ca

for TC in range(int(input())):
    K, C = map(int, input().split())
    if gcd(K, C) != 1:
        print("IMPOSSIBLE")
        continue
    if K == 1:
        print(2)
        continue

    if C == 1:
        ans = K+1
    else:
        ans = extgcd(K, C)[1]%K
    if ans > int(1e9):
        print("IMPOSSIBLE")
    else:
        print(ans)