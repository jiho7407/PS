from random import randint

TC = randint(1, 10)

print(TC)
for tc in range(TC):
    N = randint(5, 20)
    print(N)
    for i in range(N):
        print(randint(1, 100), end=' ')
    print()
