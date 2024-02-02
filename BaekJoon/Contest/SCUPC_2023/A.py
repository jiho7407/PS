import sys
input = sys.stdin.readline

N = int(input())
lst = [*input().rstrip()]

B = lst.count('B')
S = lst.count('S')
A = lst.count('A')

mx = max(A, S, B)
if mx == A == S == B:
    print("SCU")
elif mx == A == B:
    print("BA")
elif mx == A == S:
    print("SA")
elif mx == B == S:
    print("BS")
elif mx == A:
    print("A")
elif mx == B:
    print("B")
else:
    print("S")
