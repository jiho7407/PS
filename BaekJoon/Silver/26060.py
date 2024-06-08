ans = 0
N = int(input())
lst = input().split()
for _ in range(N):
    S = lst[_]
    T = []
    for i in range(len(S)):
        if S[i] in ['a', 'e', 'i', 'o', 'u', 'y']:
            T.append('1')
        else:
            T.append('0')
    ret = 1000000
    tmp = 0
    for i in range(len(T)):
        if (i % 2 and T[i] == '1') or (i % 2 == 0 and T[i] == '0'):
            tmp += 1
    ret = min(ret, tmp)
    tmp = 0
    for i in range(len(T)):
        if (i % 2 == 0 and T[i] == '1') or (i % 2 and T[i] == '0'):
            tmp += 1
    ret = min(ret, tmp)
    tmp = 0
    for i in range(len(T)):
        if T[i] == '0':
            tmp += 1
    ret = min(ret, tmp)
    ans += ret
print(ans)
