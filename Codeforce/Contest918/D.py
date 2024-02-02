import sys
input = sys.stdin.readline

V = ['a', 'e']
for TC in range(int(input())):
    n = int(input())
    cmd = input().rstrip()
    lst = []
    while True:
        if n <= 3:
            lst.append(cmd[:n])
            break
        if cmd[n-2] in V:
            lst.append(cmd[n-3:n])
            n -= 3
        else:
            lst.append(cmd[n-2:n])
            n -= 2
    lst.reverse()
    print(".".join(map(str, lst)))
