#!/usr/bin/python3
n, m = map(int, input().strip().split())
p2, p3 = n // 3, n // 3
if n % 3 == 2:
    p2 += 1
if m >= p2 + p3 + 2:
    print("Unnar")
else:
    print("Arnar")
