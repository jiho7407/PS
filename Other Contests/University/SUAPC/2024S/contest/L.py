import random

N = int(input())

ans = []
for i in range(N-1, -1, -1):
    ans.append(i)

random.shuffle(ans)


query1 = []
for i in range(N):
    query1.append(i)

query2 = []

tmpN = N
total_sum = 0

while tmpN > 0:
    tmp = 1
    while tmp * 2 <= tmpN:
        tmp *= 2
    for i in range(tmp):
        query2.append(total_sum + tmp - i - 1)
    tmpN -= tmp
    total_sum += tmp
query2.reverse()

for i in range(N):
    print(ans[i] | query1[i], end=' ')
print()
for i in range(N):
    print(ans[i] | query2[i], end=' ')
print()
print("! ", end='')
print(*ans)
