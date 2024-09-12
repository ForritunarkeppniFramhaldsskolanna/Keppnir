#!/usr/bin/env python3
a = float(input().strip())
b = float(input().strip())
if b > a:
    print("Runnun")
    exit(0)
for i in range(-7, 7):
    if abs(round(a, i) - b) < 1e-9:
        print("Veit ekki")
        exit(0)
print("Styfun")
