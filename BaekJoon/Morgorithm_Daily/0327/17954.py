N = int(input())

from collections import deque
import copy


def calc(a, b):
    Q1 = copy.deepcopy(a)
    Q2 = copy.deepcopy(b)
    cur = N * (2 * N + 1)
    sum = 0
    T = 1
    while Q1 or Q2:
        a, b, c, d = 100000, 100000, 100000, 100000
        if Q1:
            a, b = Q1[0], Q1[-1]
        if Q2:
            c, d = Q2[0], Q2[-1]
        mn = min(a, b, c, d)
        if mn == a:
            cur -= Q1.popleft()
        elif mn == b:
            cur -= Q1.pop()
        elif mn == c:
            cur -= Q2.popleft()
        else:
            cur -= Q2.pop()
        sum += cur * T
        T += 1
    return sum


if N == 1:
    print(2)
    print(1)
    print(2)
else:
    Q1 = deque()
    Q2 = deque()
    Q1.appendleft(2 * N)
    for i in range(1, N - 1):
        Q1.appendleft(i)
    Q1.appendleft(2 * N - 1)
    Q2.appendleft(2 * N - 2)
    for i in range(N - 1, 2 * N - 3):
        Q2.appendleft(i)
    Q2.appendleft(2 * N - 3)
    print(calc(Q1, Q2))
    print(*Q1)
    print(*Q2)
