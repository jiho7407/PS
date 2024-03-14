import sys

N = int(input())

lst = [[] for i in range(N+2)]
lst[0] = [i for i in range(1, N+1)]
lst[0].reverse()
print(lst)

def move(a, b):
    print(a, b)
    lst[b].append(lst[a].pop())
    if b <= N and len(lst[b]) > 2:
        print("ERROR")
        sys.exit()
    if len(lst[b]) == 2 and lst[b][-2] < lst[b][-1]:
        print("ERROR")
        sys.exit()
    print(lst)

if N%2:
    for i in range(2, N-2, 2):
        move(0, 1)
        for j in range(2, N - i, 2):
            move(j - 2, j)
        move(N - i - 1, N - i)
        for j in range(3, N - i + 1, 2):
            move(j - 2, j)
    
    for i in range(2, N, 2):
        move(i - 2, i)
    move(N - 1, N)
    move(0, 1)
    for i in range(2, N + 2, 2):
        move(i - 2, i)
    move(1, 2)
    for i in range(4, N, 2):
        move(i - 2, i)
    move(N - 1, N + 1)
    move(N, N + 1)
    for i in range(3, N - 1, 2):
        move(i, i + 1)
        for j in range(i + 1, N-1, 2):
            move(j, j + 2)
        move(N-1, N)
        move(i, i+1)
        for j in range(i+1, N, 2):
            move(j, j + 2)
        move(N, N + 1)

else:
    print(N * (N // 2 + 2) - 1)
    for i in range(2, N - 1, 2):
        move(0, 1)
        for j in range(2, N - i + 1, 2):
            move(j - 2, j)
        for j in range(3, N - i, 2):
            move(j - 2, j)
        move(N - i - 1, N - i)
    
    for i in range(0, N - 1, 2):
        move(i, i + 1)
        for j in range(i + 1, N - 2, 2):
            move(j, j + 2)
        move(N - 1, N)

        move(i, i + 1)
        for j in range(i + 1, N, 2):
            move(j, j + 2)
        move(N, N + 1)