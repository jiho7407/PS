import sys
input = sys.stdin.readline

for TC in range(int(input())):
    cmd = input().rstrip()
    did = False
    for i in range(1, len(cmd)):
        a = cmd[:i]
        b = cmd[i:]
        if b[0] == "0":
            continue
        if int(a) < int(b):
            print(int(a), int(b))
            did = True
            break
    if not did:
        print(-1)
