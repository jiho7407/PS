import math

x, y, c = map(float, input().split())

if x < y:
    x, y = y, x


def calc(h):
    A = math.sqrt(x**2 - h**2)
    B = math.sqrt(y**2 - h**2)
    C = A*B/(A+B)
    return C-c


left = 0
right = y
while True:
    h = (left+right)/2
    diff = calc(h)
    if abs(diff) < 0.0001:
        print(h)
        break
    if diff > 0:
        left = h
    else:
        right = h
