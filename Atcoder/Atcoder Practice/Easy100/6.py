a, b = map(int, input().split())
if a == 1 or b == 1:
    print(1)
elif a%2 and b%2:
    print(a*b//2 + 1)
else:
    print(a*b//2)