#!/usr/env/bin python3
res = []
n = int(input())

for i in range(n):
    prt = input()
    res.append(prt[::-1])

print("".join(res[::-1]))
