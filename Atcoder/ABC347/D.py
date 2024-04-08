import sys
a, b, C = map(int, input().split())
c = bin(C).count('1')

S = a+b+c
if S % 2:
    print(-1)
    sys.exit()
S //= 2

pa, pb, xc = S-b, S-a, S-c
if (pa+pb+xc > 60):
    print(-1)
    sys.exit()

A = 0
B = 0
acnt = 0
bcnt = 0
xcnt = 0
for i in range(60):
    if C & (1 << i):
        if acnt < pa:
            A ^= (1 << i)
            acnt += 1
        elif bcnt < pb:
            B ^= (1 << i)
            bcnt += 1
        else:
            print(-1)
            sys.exit()
    else:
        if xcnt < xc:
            A ^= (1 << i)
            B ^= (1 << i)
            xcnt += 1
if acnt == pa and bcnt == pb and xcnt == xc:
    print(A, B)
else:
    print(-1)
