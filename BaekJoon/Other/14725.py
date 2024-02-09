import sys
input = sys.stdin.readline

N = int(input())
dct = dict()

for i in range(N):
    num, *lst = map(str, input().split())
    curdct = dct
    for cmd in lst:
        if cmd in curdct:
            curdct = curdct[cmd]
        else:
            curdct[cmd] = dict()
            curdct = curdct[cmd]
    
def dfs(dfsdct, lev):
    if not dfsdct:
        return
    
    for k in sorted(dfsdct.keys()):
        print("--"*lev, end='')
        print(k)
        dfs(dfsdct[k], lev+1)
    

dfs(dct, 0)