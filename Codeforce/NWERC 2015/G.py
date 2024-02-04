import sys
input = sys.stdin.readline

N = int(input())
lst1 = [*map(int, input().split())]
lst2 = [*map(int, input().split())]
lst3 = [*map(int, input().split())]

def solve(lsta, lstb):
    lstdc = dict()
    for i in range(N):
        lstdc[lstb[i]] = i+1
    tree = [0] * (2*N)

    temp = 0
    for i in range(N):
        cmd = lstdc[lsta[i]]
        s = N+cmd
        e = 2*N
        while s < e:
            if s%2:
                temp += tree[s]
                s += 1
            if e%2:
                e -= 1
                temp += tree[e]
            s //= 2
            e //= 2
        
        idx = N+cmd-1
        while idx:
            tree[idx] += 1
            idx //= 2
    return temp

ans = N*(N-1)//2
ans -= (solve(lst1, lst2) + solve(lst1, lst3) + solve(lst2, lst3))//2

print(ans)