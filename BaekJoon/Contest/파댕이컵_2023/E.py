import sys
input = sys.stdin.readline

n, m, T = map(int, input().split())
lst = [*map(int, input().split())]

mod = int(1e9 + 7)
arr = [[0 for i in range(n+1)] for j in range(n+1)]
for i in range(m):
    cmd = [*map(int, input().split())]
    if cmd[0] == 1:
        arr[cmd[1]][cmd[2]] = 1
        arr[cmd[2]][cmd[1]] = 1
    else:
        arr[cmd[1]][cmd[2]] = 2
        arr[cmd[2]][cmd[1]] = 2
        arr[cmd[1]][cmd[3]] = 2
        arr[cmd[3]][cmd[1]] = 2
        arr[cmd[3]][cmd[2]] = 2
        arr[cmd[2]][cmd[3]] = 2


def arrmp(arr1, arr2):
    temparr = [[0 for i in range(n)] for j in range(n)]
    for row in range(n):
        for col in range(n):
            for _ in range(n):
                temparr[row][col] += arr2[row][_]*arr1[_][col]
            temparr[row][col] %= mod
    return temparr


sqarrlst = []
sqarrlst.append(arr)
for i in range(1, 31):
    sqarrlst.append(arrmp(sqarrlst[i-1], sqarrlst[i-1]))
test = list(bin(int(input()))[2:])
test.reverse()
ans = [[0 for i in range(n)] for j in range(n)]
for i in range(n):
    ans[i][i] = 1
for i in range(len(test)):
    if test[i] == "1":
        ans = arrmp(ans, sqarrlst[i])
print(ans[0][0])
