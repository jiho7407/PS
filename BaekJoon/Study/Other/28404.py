import sys
import bisect
input = sys.stdin.readline

fibo = [1, 1, 2]
while True:
    fibo.append(fibo[-1] + fibo[-2])
    if fibo[-1] > int(1e18):
        break

fibodct = dict()
for i in range(1, 87):
    fibodct[fibo[i]] = i
dct = {1:1, 2:2, 3:3, 4:6, 5:13, 6:5}

for TC in range(int(input())):
    N = int(input())
    cmd = N
    cnt = 0
    over = False
    if cmd in dct:
        print(dct[cmd])
        continue
    while cmd in fibodct:
        cmd = fibodct[cmd]
        cnt += 1
    if (cmd - bisect.bisect_left(fibo, cmd))%2 == 0:
        if cmd+1 in fibo:
            cmd += 2
        else:
            cmd += 1
    else:
        if cmd in dct:
            cmd = dct[cmd]
        elif cmd-1 in fibo:
            if cmd-2 >= 88:
                over = True
            else:
                cmd = fibo[cmd-2]
        else:
            if cmd-1 >= 88:
                over = True
            else:
                cmd = fibo[cmd-1]
    for i in range(cnt):
        if cmd >= 87:
            over = True
            break
        cmd = fibo[cmd]
    if over:
        print(-1)
    else:
        print(cmd)