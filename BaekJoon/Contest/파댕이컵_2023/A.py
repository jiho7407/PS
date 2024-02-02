import sys
input = sys.stdin.readline

T = int(input())
N = int(input())
lst = [*map(int, input().split())]

if T <= sum(lst):
    print("Padaeng_i Happy")
else:
    print("Padaeng_i Cry")
