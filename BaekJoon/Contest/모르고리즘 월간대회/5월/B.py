import sys

mod, seed, xa, xb = map(int, input().split())

for a in range(mod):
    for c in range(mod):
        if (a * seed + c) % mod == xa and (a * xa + c) % mod == xb:
            print(a, c)
            sys.exit()
