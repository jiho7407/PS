def ones(x):
    if x == 0:
        return 0
    if x == 1:
        return 1
    bins = len(bin(x)) - 3
    temp = bins * (2 ** (bins - 1))
    x -= 2 ** (bins)
    temp += x + 1
    temp += ones(x)
    return temp


a, b = map(int, input().split())
print(ones(b) - ones(a - 1))
