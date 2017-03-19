#! /usr/bin/env python3
n = int(input())
a = []
for x in range(n):
    b = input()
    a.insert(0,b)
for x in range(n):
    print(a[x])
