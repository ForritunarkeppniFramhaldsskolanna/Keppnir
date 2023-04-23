#!/usr/bin/python3
n = int(input().strip())
if n == 0:
    print("++")
    print("++")
else:
    print("+" + "-" * (n * 2 - 2) + "+")
    for i in range(n):
        print("|" + " " * (n * 2 - 2) + "|")
    print("+" + "-" * (n * 2 - 2) + "+")
