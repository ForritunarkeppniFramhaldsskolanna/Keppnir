#!/usr/bin/python3
n = int(input())
for d in range(1, n):
    for i in range(1, n + 1 - d):
        j = i + d
        print(i, j, flush=True)
        if input().strip() == "Ljos!":
            exit(0)
