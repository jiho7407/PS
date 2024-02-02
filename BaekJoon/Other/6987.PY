import sys
input = sys.stdin.readline

possible = set()

match = []
for i in range(5):
    for j in range(i+1, 6):
        match.append([i, j])


def btr(i, lst):
    if i == 15:
        temp = True
        for j in range(6):
            for k in range(3):
                if lst[j][k]:
                    temp = False
        return temp
    a, b = match[i]
    succedd = False
    if lst[a][0] > 0 and lst[b][2] > 0:
        lst[a][0] -= 1
        lst[b][2] -= 1
        if btr(i+1, lst):
            succedd = True
        lst[a][0] += 1
        lst[b][2] += 1

    if lst[a][1] > 0 and lst[b][1] > 0:
        lst[a][1] -= 1
        lst[b][1] -= 1
        if btr(i+1, lst):
            succedd = True
        lst[a][1] += 1
        lst[b][1] += 1

    if lst[a][2] > 0 and lst[b][0] > 0:
        lst[a][2] -= 1
        lst[b][0] -= 1
        if btr(i+1, lst):
            succedd = True
        lst[a][2] += 1
        lst[b][0] += 1
    if succedd:
        return True
    else:
        return False


for TC in range(4):
    origin = [*map(int, input().split())]
    lst = []
    for i in range(6):
        lst.append(origin[i*3:(i+1)*3])
    if btr(0, lst):
        print(1, end=' ')
    else:
        print(0, end=' ')
