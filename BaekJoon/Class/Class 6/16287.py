import sys
input = sys.stdin.readline

W, A = map(int, input().split())
lst = [*map(int, input().split())]

checks = [tuple() for i in range(400001)]

for i in range(A-1):
    for j in range(i+1, A):
        cmd = lst[i] + lst[j]
        if checks[cmd]:
            continue
        checks[cmd] = (i, j)

pos = False
for i in range(A-1):
    for j in range(i+1, A):
        cmd = lst[i] + lst[j]
        if W-cmd > 400000 or W-cmd < 0:
            continue
        if not checks[W-cmd]:
            continue
        if i in checks[W-cmd] or j in checks[W-cmd]:
            continue
        pos = True
if pos:
    print("YES")
else:
    print("NO")
