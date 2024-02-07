N, K, M = map(int, input().split())

def factorial(n):
    if n <= 1:
        return (1, 0)
    
    part1 = 1 # m|i가 아닌 부분
    for i in range(1, n%(2*M)+1):
        if M%i:
            part1 *= i
            part1 %= M
    
    part2 = 1 # m|i인 부분
    mx = n//M
    
    fact, cnt = factorial(mx)
    part2 *= fact

    return (part1 * part2 % M, mx+cnt)

A = factorial(N)
B = factorial(K)
C = factorial(N-K)

if A[1] > B[1] + C[1]:
    print(0)
else:
    print(A[0] * pow(B[0], -1, M) * pow(C[0], -1, M)%M)