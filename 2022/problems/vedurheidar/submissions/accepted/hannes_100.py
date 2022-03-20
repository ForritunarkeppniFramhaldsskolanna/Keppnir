#!/usr/bin/env python3
import sys

v = int(sys.stdin.readline())
n = int(sys.stdin.readline())

for i in range(n):
    name, k_i = sys.stdin.readline().split(" ")
    k_i = int(k_i)
    if v <= k_i:
        print(name, "opin")
    else:
        print(name, "lokud")
