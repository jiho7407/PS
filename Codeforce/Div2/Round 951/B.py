for TC in range(int(input())):
    x, y = map(int, input().split())
    S = bin(x ^ y)[2:]
    for i in range(len(S)):
        if S[len(S)-i-1] == '1':
            print(2**(i))
            break
