#!/usr/bin/python3
n = int(input())
for _ in range(n):
    operation, name = input().split(maxsplit=1)
    if operation == "?":
        print("invalid answer")
