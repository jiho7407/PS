import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**5)

N = int(input())
inlst = [*map(int, input().split())]
postlst = [*map(int, input().split())]

did = set()


def preorder(inleft, inright, postleft, postright):
    # print([inleft, inright, postleft, postright])
    if inleft >= inright or postleft >= postright:
        return
    if inleft == inright-1:
        print(inlst[inleft], end=' ')
        return
    root = postlst[postright-1]
    idx = inlst.index(root)
    print(root, end=' ')
    leftlen = idx-inleft
    rightlen = inright - idx - 1
    preorder(inleft, inleft+leftlen, postleft, postleft+leftlen)
    preorder(idx+1, inright, postright-1-rightlen, postright-1)


preorder(0, N, 0, N)
