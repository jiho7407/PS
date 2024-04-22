import sys
input = sys.stdin.readline

for TC in range(int(input())):
    TA, TB, VA, VB = map(int, input().split())
    ans = 0
    ans += TB*VB
    VA -= ans//TA
    left = ans%TA
    if VA<=0:
        print(ans)
    elif VA%2:
        print(ans + VA//2*TA + (TA-left))
    else:
        print(ans + VA//2*TA)