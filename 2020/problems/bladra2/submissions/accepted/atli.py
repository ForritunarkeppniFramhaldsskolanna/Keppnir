#!/usr/env/bin python3
v, a, t = [float(x) for x in input().strip().split()]
print("{:.9f}".format(v * t + a * t * t / 2.0))
