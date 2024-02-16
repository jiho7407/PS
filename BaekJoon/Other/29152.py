import sys
input = sys.stdin.readline

inf = int(1e10)
N = int(input())
LR = []
for i in range(N):
    lst = list(input())
    machine = []
    for j in range(N):
        if lst[j] == "1":
            machine.append(j)
    if machine:
        LR.append((machine[0], machine[-1]))
    else:
        if i == 0:
            LR.append((0, 0))
        else:
            LR.append(LR[-1])
print(LR)
print(machine)

dp = [[inf, inf] for i in range(N)]
