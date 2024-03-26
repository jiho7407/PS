import sys
input = sys.stdin.readline

lst = [0 for i in range(30)]
for TC in range(int(input())):
    q, v = map(int, input().split())
    if q == 1:
        lst[v] += 1
    else:
        pos = True
        nw = 0
        for i in range(30):
            r = (v % (2 << i)) // (1 << i)  # 지금 숫자가 필요한 개수
            if r > nw + lst[i]:  # 예전부터 끌고온 개수 + 이 숫자 개수
                print("NO")
                pos = False
                break
            nw = (nw + lst[i] - r) // 2
        if pos:
            print("YES")
