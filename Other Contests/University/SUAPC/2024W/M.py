import sys
input = sys.stdin.readline

N = int(input())
lst = input().split()
cmd = input().rstrip()
print(lst.count(cmd))