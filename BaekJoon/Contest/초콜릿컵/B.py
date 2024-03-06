import sys
input = sys.stdin.readline

# def pal(S):
#     S = str(S)
#     pal = True
#     for i in range(len(S)//2+1):
#         if S[i] != S[len(S)-i-1]:
#             return False
#     return True

# for i in range(10):
#     if pal(11*i):
#         print(11*i)


for i in range(int(input())):
    cmd = int(input())
    if cmd == 1:
        print(0)
        continue
    if cmd == 2:
        print(11)
        continue
    if cmd == 3:
        print(121)
        continue
    print("10" + "9"*(cmd-4) + "01")