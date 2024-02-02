N = int(input())
lst = [*map(int, input().split())]
ans = 0
for i in range(N):
    ans ^= lst[i]-2

first = input().rstrip()
if first == "Whiteking":
    if ans == 0:
        print("Blackking")
    else:
        print("Whiteking")
else:
    if ans != 0:
        print("Blackking")
    else:
        print("Whiteking")
