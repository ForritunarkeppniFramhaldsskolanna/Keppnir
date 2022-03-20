#!/usr/bin/python3
board = [input() for _ in range(3)]
print("Jebb" if sum(l.count('O') for l in board) >= sum(l.count('X') for l in board) else "Neibb")
