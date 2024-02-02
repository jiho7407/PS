import sys
input = sys.stdin.readline

for TC in range(int(input())):
    cmd = input().rstrip()
    lst = list(cmd)
    ones = lst.count("1")
    zeros = lst.count("0")
    if ones == zeros:
        print(0)
        continue
    cnt = 0
    tone = ones
    tzero = zeros
    for i in range(len(cmd)-1, -1, -1):
        if lst[i] == "1":
            ones -= 1
        else:
            zeros -= 1
        cnt += 1
        if ones <= tzero and zeros <= tone:
            print(cnt)
            break
