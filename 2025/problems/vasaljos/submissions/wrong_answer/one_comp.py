#!/usr/bin/python3
n = int(input())
for i in range(0, n, 2):
    print(i + 1, i + 2, flush=True)
    if input().strip() == "Ljos!":
        exit(0)
for i in range(0, n - 2, 2):
    print(i + 1, i + 3, flush=True)
    if input().strip() == "Ljos!":
        exit(0)
for i in range(0, n - 2, 2):
    print(i + 1, i + 4, flush=True)
    if input().strip() == "Ljos!":
        exit(0)
for i in range(0, n - 2, 2):
    print(i + 2, i + 3, flush=True)
    if input().strip() == "Ljos!":
        exit(0)
