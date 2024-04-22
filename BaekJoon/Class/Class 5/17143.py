import sys
input = sys.stdin.readline

R, C, M = map(int, input().split())
sharks = []
for i in range(M):
    sharks.append([*map(int, input().split())])  # 행, 열, 속력, 이동방향(위 아 오 왼), 크기

ans = 0
for i in range(1, C+1):
    catchable = []
    for shark in sharks:
        if shark[1] == i:
            catchable.append(shark)
    if catchable:
        catchable.sort(key=lambda x: x[0])
        caught = catchable[0]
        ans += caught[4]
        sharks.remove(caught)

    movedlst = []
    exist = set()
    for shark in sharks:
        r, c, s, d, z = shark

        if d in [1, 2]:
            s %= 2*(R-1)
            for i in range(s):
                if d == 1 and r != 1:
                    r -= 1
                elif d == 1 and r == 1:
                    r += 1
                    d = 2
                elif d == 2 and r != R:
                    r += 1
                elif d == 2 and r == R:
                    r -= 1
                    d = 1
        else:
            s %= 2*(C-1)
            for i in range(s):
                if d == 4 and c != 1:
                    c -= 1
                elif d == 4 and c == 1:
                    c += 1
                    d = 3
                elif d == 3 and c != C:
                    c += 1
                elif d == 3 and c == C:
                    c -= 1
                    d = 4

        if (r, c) in exist:
            for num, fight in enumerate(movedlst):
                if fight[0] != r or fight[1] != c:
                    continue
                if fight[4] > z:
                    break
                else:
                    movedlst[num] = [r, c, s, d, z]
        else:
            exist.add((r, c))
            movedlst.append([r, c, s, d, z])
    sharks = movedlst

print(ans)
