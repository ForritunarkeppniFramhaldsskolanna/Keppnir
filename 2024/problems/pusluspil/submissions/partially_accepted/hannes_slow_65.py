#!/usr/bin/env python3
n, m = map(int, input().split())

boxes = []
for i in range(n):
    boxes.append(list(map(int, input().split()))[1:])

pieces_found = set()

puzzle_pieces = list(range(1, m+1))
for piece in puzzle_pieces:
    for box in boxes:
        if piece in box:
            pieces_found.add(piece)

if len(pieces_found) == m:
    print("Jebb")
else:
    print("Neibb")