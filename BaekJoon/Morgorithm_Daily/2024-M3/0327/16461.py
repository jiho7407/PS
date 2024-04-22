import sys

input = sys.stdin.readline


def calc(cur, goal, lev):
    temp = 6  # 숫자버튼 누르기

    tempB = cur  # up
    for i in range(7):
        if tempB == goal:
            temp = min(temp, i)
        tempB += 20
        if tempB > 146000:
            tempB = 144000

    tempC = cur  # down
    for i in range(7):
        if tempC == goal:
            temp = min(temp, i)
        tempC -= 20
        if tempC < 144000:
            tempC = 146000

    return temp


for TC in range(int(input())):
    A, B, ch, goal = map(str, input().split())
    A = int(float(A) * 1000)
    B = int(float(B) * 1000)
    goal = int(float(goal) * 1000)
    if ch == "A":
        print(min(calc(A, goal, 0), calc(B, goal, 0) + 1))
    if ch == "B":
        print(min(calc(B, goal, 0), calc(A, goal, 0) + 1))
