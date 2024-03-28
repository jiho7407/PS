import sys
input = sys.stdin.readline

for TC in range(int(input())):
    cmd = input().rstrip().split(":")
    a = int(cmd[0])
    b = int(cmd[1])
    if a >= 12:
        AP = "PM"
    else:
        AP = "AM"

    a = a % 12
    if a == 0:
        a = 12

    if a < 10:
        a = "0" + str(a)
    if b < 10:
        b = "0" + str(b)

    print(f"{a}:{b} {AP}")
