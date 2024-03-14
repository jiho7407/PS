pi = 3.14159265358979323846
a, b, h = map(int, input().split())

if a == 0:
    print((b*b+h*h)*pi)
if a == 1:
    print((a*a+h*h)*pi*3)
