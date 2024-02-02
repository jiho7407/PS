import math

N = int(input())
lst = [*map(int, input().split())]

fl = math.floor(sum(lst)/N)
ce = math.ceil(sum(lst)/N)

ansfl = 0
ansce = 0
for i in range(N):
    cmd = lst[i]
    ansfl += (cmd-fl)**2
    ansce += (cmd-ce)**2
print(min(ansfl, ansce))
