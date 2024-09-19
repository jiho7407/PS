N = int(input())
d = int(input())

if N % 4 == 0 and (N % 100 != 0 or N % 400 == 0):
    print(30)
else:
    print(29)
