N, A, B = map(int, input().split())
S = list(input())

for stdt in S:
    if stdt == "c":
        print("No")
    elif stdt == "b":
        if B:
            B -= 1
            print("Yes")
        else:
            print("No")
    else:
        if A+B:
            if A:
                A -= 1
            else:
                B -= 1
            print("Yes")
        else:
            print("No")
