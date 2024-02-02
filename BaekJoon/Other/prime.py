import math

N = int(1e9)+9

for i in range(2, math.ceil(math.sqrt(N))):
    prime = True
    if N%i:
        continue
    prime = False
    break

print(prime)