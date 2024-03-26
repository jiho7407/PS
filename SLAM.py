import time

num = 10000

lst = [i for i in range(num)]
plst = [i for i in range(num)]

start = time.time()

for i in range(num):
    lst.extend(plst)

print(time.time() - start)
