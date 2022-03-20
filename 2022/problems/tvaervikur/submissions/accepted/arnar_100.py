#!/usr/bin/python3

n, B = map(int, input().split())
maxInd = 0
mx = -1
sm = 0
vals = list(map(int, input().split()))
for i in range(n):
    cur = (vals[i] + B - 1) // B
    sm += cur;
    if cur > mx:
        maxInd = i
        mx = cur
for i in range(n):
    if sm < 2 * mx:
        if i == maxInd:
            print("1 ", end='') 
        else:
            print("2 ", end='') 
    else:
        print("1 ", end='') 
print()
