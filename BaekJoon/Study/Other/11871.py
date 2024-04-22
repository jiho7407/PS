N = int(input())
nums = [*map(int, input().split())]
ans = 0
for i in range(N):
    if nums[i] % 2 == 0:
        ans ^= (nums[i]-2)//2
    else:
        ans ^= (nums[i]+1)//2
if ans == 0:
    print('cubelover')
else:
    print('koosaga')
