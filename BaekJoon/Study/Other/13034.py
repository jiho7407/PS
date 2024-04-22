GNlst = [0, 0, 1, 1, 2]  # 0:0, 1:0, 2:1, 3:1, 4:2

N = int(input())
for i in range(5, N+1):
    tempset = set()
    for j in range(i//2):
        tempset.add(GNlst[j] ^ GNlst[i-2-j])
    t = 0
    while True:
        if t in tempset:
            t += 1
            continue
        else:
            GNlst.append(t)
            break

if GNlst[N] == 0:
    print(2)
else:
    print(1)

print(GNlst)
