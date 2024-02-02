import sys
input = sys.stdin.readline

for TC in range(int(input())):
    N, K = map(int, input().split())
    mintree = [0 for i in range(2*N)]
    maxtree = [0 for i in range(2*N)]
    for i in range(N):
        mintree[N+i] = i
        maxtree[N+i] = i
    for i in range(N-1, 0, -1):
        mintree[i] = min(mintree[i*2], mintree[i*2+1])
        maxtree[i] = max(maxtree[i*2], maxtree[i*2+1])

    for Q in range(K):
        cmd, a, b = map(int, input().split())
        if cmd == 0:
            mintree[N+a], mintree[N+b] = mintree[N+b], mintree[N+a]
            maxtree[N+a], maxtree[N+b] = maxtree[N+b], maxtree[N+a]
            idx = (N+a)//2
            while idx >= 1:
                mintree[idx] = min(mintree[idx*2], mintree[idx*2+1])
                maxtree[idx] = max(maxtree[idx*2], maxtree[idx*2+1])
                idx //= 2
            idx = (N+b)//2
            while idx >= 1:
                mintree[idx] = min(mintree[idx*2], mintree[idx*2+1])
                maxtree[idx] = max(maxtree[idx*2], maxtree[idx*2+1])
                idx //= 2
        else:
            mn = 1e6
            mx = 0
            left = N+a
            right = N+b+1
            while left < right:
                if left % 2:
                    mn = min(mn, mintree[left])
                    mx = max(mx, maxtree[left])
                    left += 1
                if right % 2:
                    right -= 1
                    mn = min(mn, mintree[right])
                    mx = max(mx, maxtree[right])
                left //= 2
                right //= 2
            if a == mn and b == mx:
                print("YES")
            else:
                print("NO")
