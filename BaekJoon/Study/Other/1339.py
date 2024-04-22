import sys
input = sys.stdin.readline


def calc(calclst):
    temp = 0
    for i in range(8):
        temp += calclst[i] * (10**(7-i))
    return temp


N = int(input())
used = [[0 for i in range(8)] for j in range(26)]
for i in range(N):
    word = input().rstrip()
    for idx in range(len(word)):
        cur = word[idx]
        used[ord(cur)-65][8-len(word)+idx] += 1


lst = []

for i in range(26):
    lst.append(calc(used[i]))

lst.sort(reverse=True)

ans = 0
for i in range(10):
    ans += lst[i]*(9-i)
print(ans)
