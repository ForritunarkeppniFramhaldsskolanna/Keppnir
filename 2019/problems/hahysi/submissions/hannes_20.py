#!/usr/bin/env python3
n, m = [int(i) for i in input().split()]

cntr = 0

for left in range(0, n):
    for right in range(0, n):
        for up in range(0, m):
            for down in range(0, m):
                if left < right and down < up:
                    cntr += 1

mod = (10**9) + 7
print(cntr % mod)