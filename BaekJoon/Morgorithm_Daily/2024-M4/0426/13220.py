N = int(input())
S = ' '.join(input().split()*2)
T = ' '.join(input().split())

if T in S:
    print("YES")
else:
    print("NO")
