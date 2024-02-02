import sys
input = sys.stdin.readline

N = int(input())
lst = []
pos = [0 for i in range(N+1)]  # 해당 숫자의 위치(0~N-1)
for i in range(N):
    temp = int(input())
    lst.append(temp)
    pos[temp] = i+1


tree = [0 for i in range(N*2)]


def update(a):
    idx = N+a-1
    while idx >= 1:
        tree[idx] += 1
        idx //= 2


def getsum(left, right):
    left += N-1
    right += N
    tempgetsum = 0
    while left < right:
        if left % 2:
            tempgetsum += tree[left]
            left += 1
        if right % 2:
            right -= 1
            tempgetsum += tree[right]
        left //= 2
        right //= 2
    return tempgetsum


for i in range(1, N//2+1):
    curpos = pos[i]
    leftcnt = curpos - 1  # 자기 왼쪽 숫자의 개수
    print(leftcnt - getsum(1, curpos))
    update(curpos)

    curpos = pos[N-i+1]
    rightcnt = N - curpos
    print(rightcnt - getsum(curpos, N))
    update(curpos)

if N % 2:
    print(0)
