#!/usr/bin/python3

n = int(input())

def f(n):
    if n < 0:
        return 0
    elif n < 2:
        return 1
    elif n < 20:
        return 2
    elif n < 22:
        return 3
    elif n < 200:
        return 4
    elif n < 202:
        return 5
    elif n < 220:
        return 6
    elif n < 222:
        return 7
    else:
        return 8

print(f(n))
