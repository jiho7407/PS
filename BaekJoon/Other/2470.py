N = int(input())
lst = [*map(int, input().split())]
lst.sort()
left = 0
right = N-1

ans = int(1e10)
anslst = [0, N-1]

while left < right:
    cmd = lst[left] + lst[right]
    if abs(cmd) < ans:
        ans = abs(cmd)
        anslst = [left, right]
    if cmd < 0:
        left += 1
    elif cmd > 0:
        right -= 1
    else:
        break

print(lst[anslst[0]], lst[anslst[1]])
