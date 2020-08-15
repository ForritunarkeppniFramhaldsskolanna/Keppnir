#!/usr/env/bin python3
n, m = [int(x) for x in input().strip().split()]
mp = list(input().strip())

qr = int(input())

req = [int(x) for x in input().strip().split()]

pos = req[1] - 1

for _ in range(req[2]):
    if mp[pos] == '>':
        pos += 1
    else:
        pos -= 1

print(1, pos + 1)
