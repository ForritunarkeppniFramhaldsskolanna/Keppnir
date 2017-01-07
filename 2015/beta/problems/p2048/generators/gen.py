import sys
import random

digits = [2 ** i for i in range(1, 11)]
digits.append(0)

board = [[random.choice(digits) for _ in range(4)] for __ in range(4)]

print("\n".join(" ".join(str(d) for d in row) for row in board))

print(random.choice(["UP", "DOWN", "LEFT", "RIGHT"]))
