import sys

input = sys.stdin.readline

N = int(input())
tmp = list(map(int, input().split()))
box = [tmp[0], tmp[1], tmp[2], tmp[3], tmp[4], tmp[5]]  # x1, y1, z1, x2, y2, z2


def interbox(box1, box2):
    x1 = max(box1[0], box2[0])
    y1 = max(box1[1], box2[1])
    z1 = max(box1[2], box2[2])
    x2 = min(box1[3], box2[3])
    y2 = min(box1[4], box2[4])
    z2 = min(box1[5], box2[5])
    return [x1, y1, z1, x2, y2, z2]


for i in range(N - 1):
    tmp = list(map(int, input().split()))
    box = interbox(box, [tmp[0], tmp[1], tmp[2], tmp[3], tmp[4], tmp[5]])

if box[0] >= box[3] or box[1] >= box[4] or box[2] >= box[5]:
    print(0)
else:
    print(max(0, (box[3] - box[0]) * (box[4] - box[1]) * (box[5] - box[2])))
