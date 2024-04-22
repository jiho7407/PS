while True:
    S = input().rstrip()
    if S == ".":
        break
    
    N = len(S)
    pi = [0] * N
    j = 0
    for i in range(1, N):
        while j>0 and S[i] != S[j]:
            j = pi[j-1]
        if S[i] == S[j]:
            j += 1
            pi[i] = j
    
    unit = N - pi[-1]
    if N%unit:
        print(1)
    else:
        print(N//unit)