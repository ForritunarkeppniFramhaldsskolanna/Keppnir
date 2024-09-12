#!/usr/bin/env python3
a = list(input().strip().split('.')[1])
b = list(input().strip().split('.')[1])
if set(b) == set(["0"]):
    print("Veit ekki")
    exit(0)
for i in range(len(b)):
    if b[i] > a[i]:
        print("Runnun")
        exit(0)
    if b[i] < a[i]:
        if a[i] >= '5':
            print("Styfun")
        else:
            print("Veit ekki")
        exit(0)
if a[len(b)] >= '5':
    print("Styfun")
else:
    print("Veit ekki")
