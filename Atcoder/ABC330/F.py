import heapq

X = [11, 12, 13, 15, 18, 20]
N = len(X)

p = list(heapq.merge(X, map(lambda x: x - 3, X)))

print(p)
for x in X:
    print(p[N] - x, end=" ")
