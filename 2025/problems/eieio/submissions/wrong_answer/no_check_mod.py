#!/usr/bin/python3
a = int(input())
b = int(input())
res = b - 2 * a
sheep = res // 2
if 0 <= sheep <= a:
    print(sheep)
else:
    print("Rong talning")
