import sys
input = sys.stdin.readline

mod = int(1e9)+7

for TC in range(int(input())):
    S = list(input().rstrip())
    hc = S.count("H")
    qc = S.count("?")
    if qc == 0:
        if hc%2:
            print(1)
        else:
            print(0)
        continue
    print(pow(2, qc-1, mod))