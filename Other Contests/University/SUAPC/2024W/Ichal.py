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
            
ans = 0
for p in primes:
    ans ^= (len(sets[p])%2)
if ans:
    print("First")
else:
    print("Second")