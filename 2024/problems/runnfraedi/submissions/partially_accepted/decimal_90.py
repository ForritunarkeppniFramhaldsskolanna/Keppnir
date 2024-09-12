#!/usr/bin/env python3
from decimal import Decimal
from decimal import getcontext

getcontext().prec=520
a = Decimal(input().strip())
b = Decimal(input().strip())
if b > a:
    print("Runnun")
    exit(0)
for i in range(-7, 505):
    if abs(round(a, i) - b) == 0:
        print("Veit ekki")
        exit(0)
print("Styfun")
