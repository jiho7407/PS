import sys
input = sys.stdin.readline

N = int(input())

def btr(i, stk, ans):
    if i == N+1:
        print(*ans, *reversed(stk))
        return
    L = len(stk)
    for _ in range(L):
        ans.append(stk.pop())
    stk.append(i)
    btr(i+1, stk, ans)
    stk.pop()
    for _ in range(L):
        stk.append(ans.pop())
        stk.append(i)
        btr(i+1, stk, ans)
        stk.pop()
    

btr(1, [], [])