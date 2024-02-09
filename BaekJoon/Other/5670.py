import sys
input = sys.stdin.readline

def dfs(dct, cnt):
    keys = list(dct.keys())
    
    if len(keys)==1:
        k = keys[0]
        if k == "end":
            return cnt
        return dfs(dct[k], cnt)

    temp = 0
    for k in keys:
        if k == "end":
            temp += cnt
            continue
        temp += dfs(dct[k], cnt+1)

    return temp

while True:
    try:
        N = int(input())
    except:
        break
    trie = dict()
    
    for i in range(N):
        lst = list(input().rstrip())
        cur = trie
        for cmd in lst:
            if cmd not in cur:
                cur[cmd] = dict()
            cur = cur[cmd]
        cur["end"] = 1
    
    S = dfs(trie, 0)
    if len(list(trie.keys())) == 1:
        S += N
    print(f"{S/N:.2f}")
