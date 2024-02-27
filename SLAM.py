import random
import copy
import time

N = 2

sz = 48

img = [[0] * sz for i in range(sz)]
for i in range(sz):
    for j in range(sz):
        img[i][j] = int(random.randrange(0, 100))

px = [-1, -1, -1, 0, 0, 0, 1, 1, 1]
py = [-1, 0, 1, -1, 0, 1, -1, 0, 1]

# Case 1
def cunnel(_img):
    _newimg = [[0] * sz for i in range(sz)]
    for i in range(sz):
        for j in range(sz):
            temp = 0
            for p in range(9):
                x = i + px[p]
                y = i + py[p]
                if x<0 or x>=sz or y<0 or y>=sz:
                    continue
                temp+=_img[x][y]
                temp %= 131
            _newimg[i][j] = temp
    return _newimg


# Case 2
imgcube = []
for p in range(9):
    tempimg = [[0] * sz for i in range(sz)]
    for i in range(sz):
        for j in range(sz):
            x = i + px[p]
            y = j + py[p]
            if x<0 or x>=sz or y<0 or y>=sz:
                continue
            tempimg[i][j] += img[x][y]
    imgcube.append(tempimg)

"""
이미지 확인
for i in range(9):
    print(i)
    for j in range(sz):
        print(imgcube[i][j])
"""

othercube = [[[0] * sz for i in range(sz)] for j in range(9)]
for i in range(9):
    for j in range(sz):
        for k in range(sz):
            othercube[i][j][k] = int(random.randrange(0, 10))

result = [[[0] * sz for i in range(sz)] for j in range(9)]


# Case 1 calc
case1img = copy.deepcopy(img)

start = time.time()
for i in range(N):
    case1img = cunnel(case1img)
print(f"Case 1 : {time.time() - start} second")

# Case 2 calc
start = time.time()
for i in range(9):
    for j in range(sz):
        for k in range(sz):
            result[i][j][k] = imgcube[i][j][k] + othercube[i][j][k]
print(f"Case 2 : {time.time() - start} second")
