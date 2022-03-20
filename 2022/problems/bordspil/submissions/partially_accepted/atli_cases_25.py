#!/usr/bin/python3
n, m = map(int, input().split())
if m <= 1:
    print("Arnar")
elif m == 2:
    if n < 2:
        print("Unnar")
    else:
        print("Arnar")
else:
    if n < 3:
        print("Unnar")
    else:
        print("Arnar")
