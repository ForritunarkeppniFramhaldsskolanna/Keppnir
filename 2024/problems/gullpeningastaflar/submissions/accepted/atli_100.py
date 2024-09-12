#!/usr/bin/python3
n = int(input())
print("?", *range(n))
s = int(input())
print("!", s - n * n * (n - 1) // 2 + 1)
