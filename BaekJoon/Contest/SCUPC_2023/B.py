import sys
input = sys.stdin.readline

N = int(input())
lst = list(input().rstrip())
alp = [0 for i in range(26)]
for i in lst:
    cmd = ord(i)
    if 97 <= cmd <= 122:
        alp[cmd-97] += 1

print(max(alp))
