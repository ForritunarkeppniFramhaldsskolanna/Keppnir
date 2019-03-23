#!/usr/bin/python3
a,b = map(int, input().split())
c,d = map(int, input().split())
if a == c or b == d:
    print(1)
else:
    print(2)
