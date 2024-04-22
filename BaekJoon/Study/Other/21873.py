N = int(input())

print(N*(N+2))
white = True
for i in range(1, N+1):
    if white:
        for j in range(1, i+1):
            print(1, j)
        white = False
    else:
        for j in range(1, i+1):
            print(2, j)
        white = True
if white:
    for j in range(1, N+1):
        print(1, j)
    white = False
else:
    for j in range(1, N+1):
        print(2, j)
    white = True
for i in range(N, 0, -1):
    if white:
        for j in range(1, i+1):
            print(1, N-i+j)
        white = False
    else:
        for j in range(1, i+1):
            print(2, N-i+j)
        white = True