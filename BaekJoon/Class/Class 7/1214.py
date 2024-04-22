import sys
import math

D, P, Q = map(int, input().split())
if P < Q:
    P, Q = Q, P

if not D % P or not D % Q:
    print(D)
    sys.exit()

ans = int(1e15)
mods = set()
for n in range(math.ceil(D / P)):
    left = D - (n * P)
    if not left % Q:
        print(D)
        sys.exit()
    m = left // Q + 1
    result = n * P + m * Q
    ans = min(ans, result)

    result %= D
    if result in mods:
        break
    else:
        mods.add(result % D)
ans = min(ans, math.ceil(D / P) * P)
print(ans)
