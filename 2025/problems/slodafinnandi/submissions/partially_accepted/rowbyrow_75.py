#!/usr/bin/env python3
n = int(input()) // 5
tot = 0
for dy in range(-n, n + 1):
    extra = n - abs(dy)
    xstep = 0
    if dy != 0:
        xstep += 1
    side = min(max(0, abs(dy) - 1) // 2, extra)
    extra -= side
    xstep += 2 * side + extra
    tot += 2 * xstep + 1
print(tot)
