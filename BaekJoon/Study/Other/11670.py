import sys
input = sys.stdin.readline

N = int(input())

A = [None for i in range(N)]
B = dict()
links = [[] for i in range(N)]
nums = []

for i in range(N):
    a, b = map(int, input().split())
    links[i].append(a+b)
    links[i].append(a-b)
    links[i].append(a*b)
    nums.append((a, b))


def bip(a):
    visited[a] = True
    for b in links[a]:
        if b not in B or (not visited[B[b]] and bip(B[b])):
            A[a] = b
            B[b] = a
            return True
    return False


cnt = 0
for i in range(N):
    visited = [False]*N
    result = bip(i)
    if result:
        cnt += 1

if cnt != N:
    print("impossible")
    sys.exit()

for i, num in enumerate(nums):
    a, b = num
    goal = A[i]
    if a+b == goal:
        print(f"{a} + {b} = {goal}")
        continue
    if a-b == goal:
        print(f"{a} - {b} = {goal}")
        continue
    if a*b == goal:
        print(f"{a} * {b} = {goal}")
        continue
