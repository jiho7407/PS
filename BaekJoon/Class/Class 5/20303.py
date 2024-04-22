import sys
input = sys.stdin.readline

N, M, K = map(int, input().split())  # 아이들 수, 친구 관계 수, 공명 시작 최소 아이수

candylst = [0] + [*map(int, input().split())]  # 사탕 개수들
childs = [*range(N+1)]  # 일단 아이들의 친구는 자기 자신만
friends = [0] + [1 for i in range(N)]  # 각 아이에 대한 친구 집합의 크기


def root(a):
    if a == childs[a]:
        return a
    childs[a] = root(childs[a])
    return childs[a]


def merge(a, b):
    aroot = root(a)
    broot = root(b)
    if aroot != broot:
        if aroot > broot:  # 숫자가 작은쪽으로 몰자
            friends[broot] += friends[aroot]  # 친구 개수 늘려주기
            candylst[broot] += candylst[aroot]
            childs[aroot] = broot
        else:
            friends[aroot] += friends[broot]
            candylst[aroot] += candylst[broot]
            childs[broot] = aroot
        return False  # 둘은 친구관계가 아니었다
    return True  # 둘은 친구관계였다


for i in range(M):
    a, b = map(int, input().split())
    merge(a, b)

selections = []
for i in range(1, N+1):
    if i == childs[i]:
        selections.append([friends[i], candylst[i]])

selections.sort(key=lambda x: (x[0], x[1]))

bag = [0] * (K+1)
for friendcnt, candycnt in selections:
    for i in range(K, friendcnt-1, -1):
        bag[i] = max(bag[i-friendcnt]+candycnt, bag[i])

print(bag[K-1])
