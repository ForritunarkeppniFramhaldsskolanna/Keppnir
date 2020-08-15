#!/usr/env/bin python3
n = int(input())
a = [int(x) for x in input().strip().split()]

for i in range(len(a) - 2, -1, -1):
    a[i] = min(a[i], a[i + 1])

print(sum(a))

