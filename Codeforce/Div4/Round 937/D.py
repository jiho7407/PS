import sys
input = sys.stdin.readline

nums = [0, 1]
for i in range(1, 5):
    p = 10**i
    ln = len(nums)
    for j in range(ln):
        nums.append(nums[j] + p)
nums.append(100000)
DP = [False for i in range(100001)]
for num in nums:
    DP[num] = True

for i in range(100001):
    if DP[i]:
        for num in nums:
            if i*num > 100000:
                continue
            DP[i*num] = True

for TC in range(int(input())):
    N = int(input())
    if (DP[N]):
        print("YES")
    else:
        print("NO")
