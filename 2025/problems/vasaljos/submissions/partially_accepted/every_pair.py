#!/usr/bin/python3
n = int(input())
for i in range(1, n + 1):
    for j in range(i + 1, n + 1):
        print(i, j, flush=True)
        if input().strip() == "Ljos!":
            exit(0)
