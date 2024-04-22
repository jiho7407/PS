N = int(input())

ans = int((N*2)**0.5)-2
while (ans*(ans+1)//2 <= N):
    ans += 1
print(ans-1)
