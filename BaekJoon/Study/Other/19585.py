import sys
input = sys.stdin.readline

C, N = map(int, input().split())

colors = dict()

for i in range(C):
    curdct = colors
    color = input().rstrip()
    for i in range(len(color)):
        cmd = color[i]
        if cmd in curdct:
            curdct = curdct[cmd]
        else:
            curdct[cmd] = dict()
            curdct = curdct[cmd]
    curdct["end"] = 0

teams = set()
for i in range(N):
    team = input().rstrip()
    teams.add(team)

for TC in range(int(input())):
    cmd = input().rstrip()
    idx = 0
    
    curdct = colors
    pos = False

    while True:
        if idx >= len(cmd):
            break
        if "end" in curdct.keys():
            if cmd[idx:] in teams:
                pos = True
                
                
        if cmd[idx] not in curdct:
            break
        
        curdct = curdct[cmd[idx]]
        idx += 1
    
    if pos:
        print("Yes")
    else:
        print("No")

