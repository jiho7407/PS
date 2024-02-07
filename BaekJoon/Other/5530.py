import sys
from bisect import bisect_left
input = sys.stdin.readline

N = int(input())
S = input().rstrip()

Is = []
for i in range(N):
    if S[i] == "I":
        Is.append(i)

mn = 0
mx = N//3

ans = 0
while mn <= mx:
    if len(Is) == 0:
        break
    mid = (mn+mx)//2
    
    if len(Is) < mid:
        mx = mid-1
        continue

    Iidx = Is[mid*(-1)]-1

    Hcnt = 0
    Bcnt = 0
    Tcnt = 0
    for i in range(N):
        cmd = S[i]
        if cmd == "O":
            if Hcnt > Bcnt:
                Bcnt += 1
        elif cmd == "I":
            if Iidx < i:
                if Bcnt > Tcnt:
                    Tcnt += 1
            else:
                Hcnt += 1
        else:
            Hcnt += 1
    
    if Tcnt >= mid:
        ans = mid
        mn = mid + 1
    else:
        mx = mid - 1

print(ans)