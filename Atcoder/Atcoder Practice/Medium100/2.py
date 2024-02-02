S = list(input())

ans = 0
temp = 0
for cmd in S:
    if cmd == "B":
        temp += 1
    elif cmd == "W":
        ans += temp
print(ans)
