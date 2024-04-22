F = int(input())
cnt = int(input())

if F == 1:
    print(8 * cnt)
elif F == 5:
    print(8 * cnt + 4)
else:
    if cnt % 2:
        print(8 * (cnt // 2) + 4 + (5 - F))
    else:
        print(8 * (cnt // 2) + (F - 1))
