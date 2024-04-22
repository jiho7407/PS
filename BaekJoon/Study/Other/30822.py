N = int(input())

lst = [0, 0, 0, 0, 0]
dct = dict()
dct["u"] = 0
dct["o"] = 1
dct["s"] = 2
dct["p"] = 3
dct["c"] = 4

S = input().rstrip()
for i in range(N):
    if S[i] in dct:
        lst[dct[S[i]]] += 1

print(min(lst))