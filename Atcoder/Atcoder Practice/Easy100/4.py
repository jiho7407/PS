import math

N = int(input())

guess = math.floor(N/1.08)

if math.floor(guess*1.08) == N:
    print(guess)
elif math.floor((guess+1)*1.08) == N:
    print(guess+1)
else:
    print(":(")
