#!/usr/bin/python3

i = int(input())
n = int(input())

if i == 1:
    m = n
    h = 3

elif i == 2:
    m = int(input())
    h = 3

elif i == 3:
    m = int(input())
    h = int(input())

result = (n * m * h) - ((n - 2) * (m - 2) * (h - 1))
print(result)
