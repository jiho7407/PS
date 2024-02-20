import math

for i in range(1, 50):
    a = 10**i-1
    print(i+1, math.floor(math.log10(a))+1)
