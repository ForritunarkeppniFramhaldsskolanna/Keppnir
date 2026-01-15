#!/usr/bin/python3
n = int(input())
for i in range(0, n, 2):
    print(i + 1, i + 2, flush=True)
    if input().strip() == "Ljos!":
        exit(0)
for a, b in [(1, 3), (1, 4), (2, 3), (2, 4)]:
    print(a, b, flush=True)
    if input().strip() == "Ljos!":
        exit(0)
assert False
