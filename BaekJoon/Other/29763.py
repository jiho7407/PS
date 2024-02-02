N, M = map(int, input().split())
X = int(input(),2)

mod = int(1e9)+7

def calc(a, b):
    if b == 0:
        return 1
    if b == 1:
        return a
    
    half = calc(a, b//2)

    if b%2:
        return (half*half%mod)*a%mod
    else:
        return half*half%mod
    
if N == 1:
    print(X%mod)
else:
    print((calc(2, M)-1)*(N%mod)%mod*pow(2, -1, mod)%mod)
