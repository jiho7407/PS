import sys
input = sys.stdin.readline

N, X = map(int, input().split())
card = [*map(int, input().split())]

primes = []
sets = dict()
p = 2
while X>1:
    if p*p > X:
        primes.append(X)
        break
    if X%p:
        p += 1
        continue
    X //= p
    primes.append(p)

primes = set(primes)

for p in primes:
    sets[p] = []

for cmd in card:
    for p in primes:
        if not cmd%p:
            sets[p].append(cmd)
extnum = []
for idx, cmd in enumerate(card):
    ext = []
    for p in primes:
        if cmd in sets[p]:
            ext.append((cmd, p))
    if len(ext) == 1:
        extnum.append(ext[0])
    win = True
    for cmd, p in ext:
        if not len(sets[p]) % 2:
            win = False
    if win:
        print("First")
        sys.exit()

if extnum:
    odd = False
    for cmd, p in extnum:
        if len(sets[p])%2:
            odd = True
    if odd:
        print("First")
    else:
        print("Second")
    sys.exit()
    