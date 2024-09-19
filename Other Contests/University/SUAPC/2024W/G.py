lst = [0, 0, 1, 1, 0, 1]

N = len(lst)

def xor(xorlst):
    xor = 0
    for cmd in xorlst:
        xor ^= cmd
    return xor

for i in range(N-1):
    for j in range(i, N):
        print(i, j, xor(lst[i:j+1]))