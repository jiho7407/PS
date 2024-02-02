S = input()

lst = [0 for i in range(len(S))]
rcnt = 0
lcnt = 0
Rs = True
idx = 0
for i, cmd in enumerate(S):
    if not Rs:
        if cmd == "R":
            lst[idx-1] += lcnt//2
            lst[idx-1] += rcnt - rcnt//2
            lst[idx] += lcnt - lcnt//2
            lst[idx] += rcnt // 2
            rcnt, lcnt = 1, 0
            Rs = True
        elif cmd == "L":
            lcnt += 1
    else:
        if cmd == "R":
            rcnt += 1
        else:
            lcnt += 1
            idx = i
            Rs = False
    # print(lst, Rs, rcnt, lcnt)
lst[idx-1] += lcnt//2
lst[idx-1] += rcnt - rcnt//2
lst[idx] += lcnt - lcnt//2
lst[idx] += rcnt // 2
print(*lst)
