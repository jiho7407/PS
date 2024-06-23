K, S, E = map(int, input().split())
N = int(input())
tower = [[] for _ in range(K)]
for i in range(K*(K-1)//2, 0, -1):
    tower[S-1].append(i)

for i in range(N):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    tower[b].append(tower[a].pop())

    print(tower)
