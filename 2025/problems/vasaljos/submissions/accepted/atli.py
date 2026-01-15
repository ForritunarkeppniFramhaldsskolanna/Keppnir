#!/usr/bin/python3
n = int(input())


def guess(i, j):
    print(i, j, flush=True)
    if input().strip() == "Ljos!":
        exit(0)


if n == 4:
    for i in range(4):
        for j in range(i + 1, 4):
            guess(i + 1, j + 1)
guess(1, 2)
guess(1, 3)
guess(2, 3)
guess(4, 5)
guess(4, 6)
guess(5, 6)
for i in range(7, n, 2):
    guess(i, i + 1)
