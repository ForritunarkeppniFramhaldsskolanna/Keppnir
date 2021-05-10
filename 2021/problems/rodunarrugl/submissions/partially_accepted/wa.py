#!/usr/bin/env python3
_, s = input(), sum([x != i + 1 for (i, x) in enumerate([int(y) for y in input().strip().split()])])
print(0 if s == 0 else s + 1)
