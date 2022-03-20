#!/bin/usr/python3

import sys

n, k, d = map(int, sys.stdin.readline().split())

sm = 0
for i in range(n):
    m = int(sys.stdin.readline())
    if d+k >= m+14:
        sm += 1
sys.stdout.write(str(sm)+"\n")
