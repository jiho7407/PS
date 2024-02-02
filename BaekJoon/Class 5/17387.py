# 입력받아 점 만들기
x1, y1, x2, y2 = map(int, input().split())
x3, y3, x4, y4 = map(int, input().split())
p1 = (x1, y1)
p2 = (x2, y2)
p3 = (x3, y3)
p4 = (x4, y4)

# CCW (Counter Clock Wise)


def CCW(P1, P2, P3):
    vector_a = (P2[0]-P1[0], P2[1]-P1[1])
    vector_b = (P3[0]-P2[0], P3[1]-P2[1])
    result = vector_a[0]*vector_b[1] - vector_a[1]*vector_b[0]
    if result > 0:  # 반시계
        return -1
    elif result == 0:  # 일직선
        return 0
    else:  # 시계
        return 1


check1 = CCW(p1, p2, p3)*CCW(p1, p2, p4)
check2 = CCW(p3, p4, p1)*CCW(p3, p4, p2)
if check1 == 0 and check2 == 0:  # 일직선에 있을때
    a = min(p1, p2)
    b = max(p1, p2)
    c = min(p3, p4)
    d = max(p3, p4)

    if b >= c and a <= d:
        print(1)
    else:
        print(0)
elif check1 <= 0 and check2 <= 0:
    print(1)
else:
    print(0)
