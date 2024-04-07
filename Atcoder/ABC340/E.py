import sys
import heapq
input = sys.stdin.readline

class LazySegmentTree:
    def __init__(self, size):
        self.size = size
        self.tree = [0] * (4 * size)
        self.lazy = [0] * (4 * size)
    
    def update_range(self, node, start, end, left, right, val):
        self.propagate(node, start, end)
        if start > right or end < left:
            return
        if left <= start and end <= right:
            self.tree[node] += (end - start + 1) * val
            if start != end:
                self.lazy[node*2] += val
                self.lazy[node*2+1] += val
            return
        mid = (start + end) // 2
        self.update_range(node*2, start, mid, left, right, val)
        self.update_range(node*2+1, mid+1, end, left, right, val)
        self.tree[node] = self.tree[node*2] + self.tree[node*2+1]
    
    def query(self, node, start, end, idx):
        self.propagate(node, start, end)
        if start == end:
            return self.tree[node]
        mid = (start + end) // 2
        if idx <= mid:
            return self.query(node*2, start, mid, idx)
        else:
            return self.query(node*2+1, mid+1, end, idx)
    
    def propagate(self, node, start, end):
        if self.lazy[node] != 0:
            self.tree[node] += (end - start + 1) * self.lazy[node]
            if start != end:
                self.lazy[node*2] += self.lazy[node]
                self.lazy[node*2+1] += self.lazy[node]
            self.lazy[node] = 0

    
N, M = map(int, input().split())
lst = [*map(int, input().split())]
Q = [*map(int, input().split())]

tree = LazySegmentTree(N)
for idx, cmd in enumerate(lst):
    tree.update_range(1, 0, N-1, idx, idx, cmd)

for cmd in Q:
    val = tree.query(1, 0, N-1, cmd)

    tree.update_range(1, 0, N-1, cmd, cmd, -val)
    tree.update_range(1, 0, N-1, 0, N-1, val//N)
    
    R = val%N
    if cmd + R < N:
        tree.update_range(1, 0, N-1, cmd+1, cmd+R, 1)
    else:
        tree.update_range(1, 0, N-1, cmd+1, N-1, 1)
        tree.update_range(1, 0, N-1, 0, cmd+R-N, 1)

for i in range(N):
    print(tree.query(1, 0, N-1, i), end=" ")