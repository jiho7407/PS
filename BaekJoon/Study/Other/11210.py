def extgcd(a, b):
    ca = (1, 0)
    cb = (0, 1)
    while b:
        q, r = divmod(a, b)

        a, b = b, r
        
        cr = (ca[0] - q*cb[0], ca[1] - q*cb[1])
        ca, cb = cb, cr

    return ca
 
def CRT(a1, m1, a2, m2):
    xp, yp = extgcd(m1, m2)
    return (xp*m1*a2 + yp*m2*a1)%(m1*m2)

def solve(a1, a2, a3, m1, m2, m3):
    temp = CRT(a1, m1, a2, m2)
    return CRT(temp, m1*m2, a3, m3)

m1, m2, m3 = map(int, input().split())
x1, x2, x3 = map(int, input().split())
y1, y2, y3 = map(int, input().split())

ans = int(1e30)

for i in range(y1*(-1), y1+1):
    for j in range(y2*(-1), y2+1):
        a1 = (x1+i)%m1
        a2 = (x2+j)%m2
        a3 = (x3-y3)%m3
        ans = min(ans, solve(a1, a2, a3, m1, m2, m3))

for i in range(y1*(-1), y1+1):
    for k in range(y3*(-1), y3+1):
        a1 = (x1+i)%m1
        a2 = (x2-y2)%m2
        a3 = (x3+k)%m3
        ans = min(ans, solve(a1, a2, a3, m1, m2, m3))

for j in range(y2*(-1), y2+1):
    for k in range(y3*(-1), y3+1):
        a1 = (x1-y1)%m1
        a2 = (x2+j)%m2
        a3 = (x3+k)%m3
        ans = min(ans, solve(a1, a2, a3, m1, m2, m3))

check = [False] * 3
for i in range(y1*(-1), y1+1):
    if not (x1+i)%m1:
        check[0] = True
        break

for i in range(y2*(-1), y2+1):
    if not (x2+i)%m2:
        check[1] = True
        break

for i in range(y3*(-1), y3+1):
    if not (x3+i)%m3:
        check[2] = True
        break

if check[0] and check[1] and check[2]:
    print(0)
else:
    print(ans)