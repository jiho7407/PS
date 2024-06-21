N, M, K = map(int, input().split())
ans = N - M * 3
dct = {1: 3, 2: 2, 4: 2, 8: 1, 3: 2, 6: 1, 5: 1, 7: 1, 9: 1}
ans += dct[K]
print(ans)
