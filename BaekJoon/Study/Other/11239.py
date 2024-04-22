import sys
input = sys.stdin.readline

mod = int(1e12)+137
B = 27


def chartonum(a):
    return ord(a)-96


def hashing(S):
    Slen = len(S)
    Snum = 0
    for i in range(Slen):
        Snum = (Snum*B+chartonum(S[i])) % mod
    return Snum

def RabinKarp(S, Tdct, Tlen):
    Slen = len(S)
    Snum = 0

    if Slen < Tlen:
        return []

    BS = pow(B, Tlen-1, mod)
    
    for i in range(Tlen):
        Snum = (Snum*B+chartonum(S[i])) % mod

    temp = []
    if Snum in Tdct:
        temp.append(Tdct[Snum])

    for i in range(Tlen, Slen):
        Snum = (Snum - BS*chartonum(S[i-Tlen]) % mod + mod) % mod
        Snum = (Snum*B+chartonum(S[i])) % mod
        if Snum in Tdct.keys():
            temp.append(Tdct[Snum])
    return temp

for TC in range(int(input())):
    Mlst = [dict() for i in range(51)]
    for N in range(int(input())):
        M = input().rstrip()
        Mlst[len(M)][hashing(M)] = M
    
    for i in range(int(input())):
        ans = []
        S = input().rstrip()
        for j in range(6, 51):
            if not Mlst[j]:
                continue
            ans += RabinKarp(S, Mlst[j], j)
        if not ans:
            print("NO")
        elif len(ans) == 1:
            print(ans[0])
        else:
            print("AMBIGUOUS")            