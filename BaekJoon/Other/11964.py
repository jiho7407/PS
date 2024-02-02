T, A, B = map(int, input().split())

mx = 0

for i in range(T//A + 1):  # A를 하나 두개 넣어보면서 나머지 B로 채우기
    mx = max(mx, A * i + ((T-A*i)//B)*B)

H1 = T - A//2
for i in range(H1//A + 1):
    mx = max(mx, A * i + ((H1-A*i)//B)*B + A//2)
H2 = T - B//2

for i in range(H2//A + 1):
    mx = max(mx, A * i + ((H2-A*i)//B)*B + B//2)

if A+B < T:
    H3 = T - (A+B)//2

    for i in range(H3//A + 1):
        mx = max(mx, A * i + ((H3-A*i)//B)*B + (A+B)//2)

print(mx)
