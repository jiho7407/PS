import sys

input = sys.stdin.readline
sys.setrecursionlimit(2 * int(1e6))

N = int(input())
leaf = "1!23qe!@#$VAS56C!11"

dct = dict()
dct[leaf] = N
ans = 0
for i in range(N):
    cmd = input().rstrip().split("/")
    curdct = dct
    ans += len(cmd) - 1
    for i in range(1, len(cmd) - 1):
        dr = cmd[i]
        if dr not in curdct.keys():
            curdct[dr] = dict()
            curdct[dr][leaf] = 0
        curdct = curdct[dr]
        curdct[leaf] += 1


def dfs(cur: dict, cnt):
    global ans
    for goal in cur.keys():
        if goal == leaf:
            continue
        ans = min(ans, cnt + N - 2 * cur[goal][leaf])
        dfs(cur[goal], cnt + N - 2 * cur[goal][leaf])


dfs(dct, ans)
print(ans)
