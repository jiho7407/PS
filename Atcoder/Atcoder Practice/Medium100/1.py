N = int(input())
lst = [0]
for i in range(N):
    lst.append(int(input()))
idx = 1
visited = [False for i in range(N+1)]
visited[1] = True

cnt = 0
while True:
    idx = lst[idx]
    cnt += 1
    if idx == 2:
        print(cnt)
        break
    if visited[idx]:
        print(-1)
        break
    visited[idx] = True
