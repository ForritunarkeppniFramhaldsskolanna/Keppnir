#! /usr/bin/env python3
n = int(input())
a = [input() for _ in range(n)]
for x in range(n,0,-1):
    print(a[x -1])
