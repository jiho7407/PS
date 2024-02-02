import sys
input = sys.stdin.readline
mod = 1000000007


def Binormal(N, K):
    smaller = min(K, N-K)

    a, b = 1, 1
    for i in range(1, smaller+1):
        a = a * (N-i+1) % mod
        b = b * i % mod
    return (a*pow(b, -1, mod)) % mod


# for n in range(1, 11):
#     ans = 0
#     for i in range(n+1):
#         ans += i * Binormal(n, i)
#         print(ans, end=' ')
#     print(ans)

# for n in range(2, 13):
#     print(2**(n-2)*(n-1), end=' ')

# lst = [1, 2]
# for i in range(10):
#     lst.append(lst[-1]*2+2**(i))
# print(lst)

lst1 = [*map(int, input().split())]
lst2 = [*map(int, input().split())]
lst3 = [*map(int, input().split())]
for i in range(len(lst1)):
    print(lst1[i]-lst2[i], end=' ')
print()
for i in range(len(lst1)):
    print(lst2[i]-lst3[i], end=' ')
