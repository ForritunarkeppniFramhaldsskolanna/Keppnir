#!/usr/bin/python3
n = int(input())
for i in range(0, n - 3, 3):
    print(i + 1, i + 2, flush=True)
    if input().strip() == "Ljos!":
        exit(0)
    print(i + 1, i + 3, flush=True)
    if input().strip() == "Ljos!":
        exit(0)
    print(i + 2, i + 3, flush=True)
    if input().strip() == "Ljos!":
        exit(0)
print(n - 1, n)
if input().strip() == "Ljos!":
    exit(0)
print(n - 2, n)
if input().strip() == "Ljos!":
    exit(0)
print(n - 3, n)
if input().strip() == "Ljos!":
    exit(0)
print(n - 2, n - 1)
