import sys

pi = 3.14159265358979323846
a, b, h = map(int, input().split())
if a == b:
    print(-1)
    sys.exit()
if (a > b):
    a, b = b, a
h2 = a*h/(b-a)
print((b*b+(h+h2)*(h+h2)-a*a-h2*h2)*pi)
