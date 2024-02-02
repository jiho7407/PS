N, K = map(int, input().split())

lst = list(input())

stk = []
erased = 0

for i in range(N):
    cmd = lst[i]
    if not stk:
        stk.append(cmd)
        continue
    
    while stk and erased < K and int(stk[-1]) < int(cmd):
        stk.pop()
        erased += 1
    stk.append(cmd)

for i in range(erased, K):
    stk.pop()

print(''.join(stk))