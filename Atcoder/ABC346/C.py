import sys
# sys.setrecursionlimit(10**6)
input = sys.stdin.readline

N, K = map(int, input().split())
lst = [*map(int, input().split())]
st = set(lst)
S = K*(K+1)//2

for s in st:
    if s <= K:
        S -= s

print(S)
