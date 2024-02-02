import sys
import bisect

input = sys.stdin.readline

# 입력받기
N, S = map(int, input().split())
lst = [*map(int, input().split())]


# 리스트 두개로 쪼개기 (중간에서 만나기 이용)
mid = N // 2
lsta = lst[:mid]
lstb = lst[mid:]
lsta.sort()
lstb.sort()

# 리스트 a로 만들 수 있는 수들 저장하기
sumlsta = []


def btra(a, sum):
    if a == len(lsta):
        sumlsta.append(sum)
        return
    btra(a + 1, sum + lsta[a])
    btra(a + 1, sum)
    return


btra(0, 0)
sumlsta.sort()

# 리스트 b로 만들 수 있는 수들 저장하기
sumlstb = []


def btrb(a, sum):
    if a == len(lstb):
        sumlstb.append(sum)
        return
    btrb(a + 1, sum + lstb[a])
    btrb(a + 1, sum)
    return


btrb(0, 0)
sumlstb.sort()

# 답내기
ans = 0
for i in sumlsta:
    target = S - i
    ans += bisect.bisect_right(sumlstb, target)
    ans -= bisect.bisect_left(sumlstb, target)
if S == 0:
    ans -= 1

# 테스트
# print(sumlsta)
# print(sumlstb)
print(ans)
