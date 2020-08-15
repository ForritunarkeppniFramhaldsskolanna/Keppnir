#!/usr/env/bin python3
n = input()
r = 0

for i in range(len(n) + 1):
    if i == len(n):
        r += 1
        continue
    if n[i] == '0':
        continue
    if n[i] == '1':
        r += 2 ** (len(n) - i - 1)
        break
    if n[i] == '2':
        r += 2 ** (len(n) - i - 1)
        continue
    r += 2 ** (len(n) - i)
    break

print(r)

