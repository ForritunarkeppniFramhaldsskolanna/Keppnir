#!/usr/bin/python3
n = int(input())
print("?", *range(n, 2*n))
s = int(input()) - n * n
print("!", s - n * n * (n - 1) // 2 + 1)
