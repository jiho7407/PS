import sys
input = sys.stdin.readline

N, M = map(int, input().split())
NA = [0] * (N+1)
MA = [0] * (M+1)
links = [[] for i in range(N+1)]

for i in range(N):
    num, *lst = map(int, input().split())
    for j in range(num):
        links[i+1].append(lst[j])
visted = [False] * (N+1)


def binmatch(a):
    visited[a] = True
    for goal in links[a]:
        if not MA[goal] or (not visited[MA[goal]] and binmatch(MA[goal])):
            NA[a] = goal
            MA[goal] = a
            return True
    return False


ans = 0
for i in range(1, N+1):
    if not NA[i]:
        visited = [False] * (N+1)
        result = binmatch(i)
        if result:
            ans += 1
print(ans)
