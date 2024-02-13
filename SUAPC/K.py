import sys
import copy
input = sys.stdin.readline
sys.setrecursionlimit(2*int(1e5)+100)

N = 200000  # 나중에 수정할것
fron = [i for i in range(N+1)]
back = [i for i in range(N+1)]
nextlst = [i for i in range(N+1)]

for i in range(int(input())):
    num, *lst = map(int, input().split())
    if num == 1:
        continue
    back[lst[0]] = lst[-1]
    fron[lst[-1]] = lst[0]
    for j in range(1, num-1):
        fron[lst[j]] = lst[0]
        back[lst[j]] = lst[-1]
    for j in range(num-1):
        nextlst[lst[j]] = lst[j+1]

front = copy.deepcopy(fron)


def findfront(a):
    if a == front[a]:
        return a
    else:
        front[a] = findfront(front[a])
    return front[a]


def findback(a):
    if a == back[a]:
        return a
    else:
        back[a] = findback(back[a])
    return back[a]


def merge(a, b):
    nextlst[findback(a)] = findfront(b)
    front[findfront(b)] = findfront(a)
    back[findback(a)] = findback(b)


query = []
for i in range(int(input())):
    query.append(tuple(map(int, input().split())))

for cmd, a, b in query:
    if cmd == 1:
        if findfront(a) == findfront(b):
            continue
        else:
            merge(a, b)

dct = dict()
curidx = 0
for i in range(1, N+1):
    if findfront(i) == i:
        cur = i
        while cur != nextlst[cur]:
            dct[cur] = curidx
            curidx += 1
            cur = nextlst[cur]
        dct[cur] = curidx
        curidx += 1

tree = [0] * (2*N)

for i in range(1, N+1):
    tree[N + dct[i]] = i

for i in range(N-1, 0, -1):
    tree[i] = tree[i*2] + tree[i*2+1]


def solve(a, b):
    a = dct[a]
    b = dct[b]
    if a > b:
        a, b = b, a

    temp = 0
    a += N
    b += N+1
    while a < b:
        if a % 2:
            temp += tree[a]
            a += 1
        if b % 2:
            b -= 1
            temp += tree[b]
        a //= 2
        b //= 2
    return temp


front = copy.deepcopy(fron)


def merge2(a, b):
    afront = findfront(a)
    bfront = findfront(b)
    if afront == bfront:
        print("NO")
        return False

    if afront < bfront:
        front[bfront] = a
    else:
        front[afront] = b
    print("YES")
    return True


for cmd, a, b in query:
    if cmd == 1:
        merge2(a, b)
    else:
        if findfront(a) == findfront(b):
            print(solve(a, b))
        else:
            print(-1)
