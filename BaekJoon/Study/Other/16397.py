import sys
import math
from collections import deque
input = sys.stdin.readline

N, T, G = map(int, input().split())


def buttonA(btnA_N):
    return btnA_N+1


def buttonB(btnB_N):
    cur = btnB_N*2
    if cur >= 100000:
        return -1
    if cur == 0:
        return 0
    return cur - 10**math.floor(math.log10(cur))


Q = deque()
Q.append((N, 0))
visited = set()
while Q:
    cur, lev = Q.popleft()
    if lev > T:
        print("ANG")
        break
    if cur == G:
        print(lev)
        break
    if cur+1 not in visited:
        Q.append((buttonA(cur), lev+1))
        visited.add(cur+1)
    temp = buttonB(cur)
    if temp != -1 and temp not in visited:
        Q.append((buttonB(cur), lev+1))
        visited.add(temp)
