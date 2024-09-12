#!/usr/bin/env python3

n, m = map(int, input().split())

puzzle_pieces = []

for i in range(n):
    puzzle_pieces.extend(map(int, input().split()[1:]))

if len(set(puzzle_pieces)) == m:
    print("Jebb")
else:
    print("Neibb")