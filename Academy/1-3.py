TC = int(input())

for _ in range(TC):
    Q = input()
    A, op, B = Q.split()
    if (op == "plus"):
        print(int(A) + int(B))
    elif (op == "minus"):
        print(int(A) - int(B))
