from math import gcd

def extgcd(a, b):
    ca = (1, 0)
    cb = (0, 1)
    while b:
        q, r = divmod(a, b)

        a, b = b, r
        
        cr = (ca[0] - q*cb[0], ca[1] - q*cb[1])
        ca, cb = cb, cr

    return ca


A, B = map(int, input().split())
if A == 0:
    B = abs(B)
elif B == 0:
    A = abs(A)

g = abs(gcd(A, B))
if g not in [1, 2]:
    print(-1)
else:
    X, Y = extgcd(A, B)
    if g == 1:
        X *= 2
        Y *= 2
    print(Y, X*(-1))