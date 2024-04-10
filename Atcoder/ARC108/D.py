import sys
input = sys.stdin.readline

N = int(input())
mod = int(1e9)+7

lst = []
CAA = input().rstrip()
CAB = input().rstrip()
CBA = input().rstrip()
CBB = input().rstrip()

Fibo = [1, 1]
for i in range(2, N):
    Fibo.append(Fibo[i-1] + Fibo[i-2])
    Fibo[i] %= mod

if N <= 3:
    print(1)
    sys.exit()

if CAB == 'A':
    if CAA == 'A':
        print(1)
    elif CAA == 'B':
        if CBA == 'B':
            print(pow(2, N-3, mod))
        else:
            print(Fibo[N-2])
elif CAB == 'B':
    if CBB == 'B':
        print(1)
    elif CBB == 'A':
        if CBA == 'A':
            print(pow(2, N-3, mod))
        else:
            print(Fibo[N-2])
