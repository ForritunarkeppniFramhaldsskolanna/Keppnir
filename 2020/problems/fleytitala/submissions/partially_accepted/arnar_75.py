#!/usr/bin/python3
d = float(input())
sm = d
x = d
for i in range(int(input())):
    x /= 2
    sm += x
print(sm)
