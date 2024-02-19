import sys
import heapq
input = sys.stdin.readline

n = int(input())
heap = []
for i in range(n):
    cmd = int(input())
    if cmd == 0:
        if len(heap) == 0:
            print(0)
        else:
            print(heapq.heappop(heap))
    else:
        heapq.heappush(heap, cmd)