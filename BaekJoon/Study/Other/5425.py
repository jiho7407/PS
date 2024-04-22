import sys
from math import log10, floor

input = sys.stdin.readline

#dp[자리][합][제한여부]
dp = [[[-1 for i in range(2)] for j in range(136)] for k in range(16)]

def digitlst(n):
    dglst = []
    while n>0:
        dglst.append(n%10)
        n //= 10
    return dglst

def digitsum(idx, dgsum, prohibit, digit): #10^idx자리, 자리수 합, 제한여부, 숫자들
    #끝났으면
    if idx == -1:
        return dgsum
    
    #계산되어있고 제한이 없는 상황 -> 메모이제이션 이용
    if dp[idx][dgsum][prohibit] != -1 and prohibit == 0:
        return dp[idx][dgsum][prohibit]
    
    temp = 0
    k = 9
    if prohibit:
        k = digit[idx]
    for i in range(k+1):
        if digit[idx] == i:
            temp += digitsum(idx-1, dgsum+i, prohibit, digit)
        else:
            temp += digitsum(idx-1, dgsum+i, 0, digit)
    if not prohibit:
        dp[idx][dgsum][prohibit] = temp
    return temp

for TC in range(int(input())):
    a, b = map(int, input().split())
    a -= 1
    alst = digitlst(a)
    blst = digitlst(b)
    print(digitsum(len(blst)-1, 0, 1, blst) - digitsum(len(alst)-1, 0, 1, alst))