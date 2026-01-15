#!/usr/bin/python3
a = int(input())
b = int(input())
res = b - 2 * a
sheep = res // 2
if res % 2 == 0 and 0 <= sheep:
    print(sheep)
else:
    print("Rong talning")
