#!/usr/bin/python3
a = int(input())
b = int(input())
res = b - 2 * a
if res < 0 or res % 2 != 0 or (a - res // 2) < 0:
    print("Rong talning")
else:
    print(res // 2)
