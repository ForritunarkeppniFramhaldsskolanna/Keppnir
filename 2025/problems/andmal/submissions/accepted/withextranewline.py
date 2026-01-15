#!/usr/bin/python3
x = input().strip()
if len(x) < 10:
    print(x + "a\n\n")
else:
    extra = "a" if x[0] != "a" else "b"
    print(extra + x[1:] + "\n")
