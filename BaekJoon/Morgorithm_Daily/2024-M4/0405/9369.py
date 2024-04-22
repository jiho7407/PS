import sys

input = sys.stdin.readline


def match(S, T):
    dct = dict()
    if len(S) != len(T):
        return False
    for i in range(len(S)):
        if S[i] not in dct:
            dct[S[i]] = T[i]
        else:
            if dct[S[i]] != T[i]:
                return False
    return dct


for TC in range(int(input())):
    N = int(input())
    password = []
    for i in range(N):
        password.append(list(input().rstrip()))
    solved = list(input().rstrip())
    pos = [True] * N
    for i in range(N):
        if not match(password[i], solved):
            pos[i] = False
        if not match(solved, password[i]):
            pos[i] = False
    anslst = list(input().rstrip())
    poscnt = pos.count(True)
    if poscnt == 0:
        print("IMPOSSIBLE")
        continue
    elif poscnt == 1:
        posidx = pos.index(True)
        posdct = match(password[posidx], solved)
    else:
        posdct = "NOTYET"
        for i in range(N):
            if pos[i]:
                if posdct == "NOTYET":
                    posdct = match(password[i], solved)
                    continue
                testdct = match(password[i], solved)
                keys = list(posdct.keys())
                for key in keys:
                    if key not in posdct:
                        continue
                    if key not in list(testdct.keys()):
                        del posdct[key]
                        continue
                    if posdct[key] != testdct[key]:
                        del posdct[key]
    if len(posdct) == 25:
        for i in range(26):
            items = [v for k, v in posdct.items()]
            if chr(ord("a") + i) not in items:
                char = chr(ord("a") + i)
                break
        for i in range(26):
            if chr(ord("a") + i) not in posdct.keys():
                posdct[chr(ord("a") + i)] = char
                break
    for i in anslst:
        if i in posdct:
            print(posdct[i], end="")
        else:
            print("?", end="")
    print()
