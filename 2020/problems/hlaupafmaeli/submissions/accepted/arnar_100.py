#!/usr/bin/python3

def f(x):
    return x//4 - x//100 + x//400

def leap(x):
    return (x%4 == 0 and x%100 != 0) or x % 400 == 0

Y = int(input())
if leap(Y):
    print(f(Y)-f(2020))
else:
    print("Neibb")
