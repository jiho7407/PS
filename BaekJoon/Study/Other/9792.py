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
        Snum = (Snum*26+chartonum(S[i])) % mod
    return Snum


def RabinKarp(S, T):
    Slen = len(S)
    Snum = 0
    Tlen = len(T)
    Tnum = 0

    if Slen < Tlen:
        return False

    BS = pow(B, Tlen-1, mod)
    for i in range(Tlen):
        Snum = (Snum*B+chartonum(S[i])) % mod
        Tnum = (Tnum*B+chartonum(T[i])) % mod
    if Snum == Tnum:
        return True

    for i in range(Tlen, Slen):
        Snum = (Snum - BS*chartonum(S[i-Tlen]) % mod + mod) % mod
        Snum = (Snum*B+chartonum(S[i])) % mod
        if Snum == Tnum:
            return True
    return False


lyrics = [input().rstrip() for i in range(int(input()))]

for idx, lyric in enumerate(lyrics):
    lyriclen = len(lyric)
    mx = [0, 0, 0]
    hashset = set()
    for i in range(0, lyriclen):
        Snum = 0
        for j in range(i, lyriclen):
            Snum = (Snum*26+chartonum(lyric[j])) % mod
            if Snum in hashset:
                if j-i < mx[0]:
                    continue
                mx = [j-i, i, j]
            else:
                hashset.add(Snum)
    lyrics[idx] = lyric[mx[1]:mx[2]+1]

for q in range(int(input())):
    part = input().rstrip()
    lst = []
    for idx, lyric in enumerate(lyrics):
        if RabinKarp(lyric, part):
            lst.append(idx)
    if lst:
        print(*lst)
    else:
        print(-1)
