N = 8

xors = [0] * N
for i in range(N):
    for j in range(N):
        xors[i ^ j] += 1

print(xors)
