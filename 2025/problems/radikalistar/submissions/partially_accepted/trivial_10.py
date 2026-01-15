#!/usr/bin/python3
n, q = map(int, input().strip().split())
for _ in range(q):
    inp = input().strip().split()
    if inp[0] == "s":
        print(1)
    if inp[0] == "m":
        print(*range(1, n + 1))
