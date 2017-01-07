import sys
import random

digits = [2 ** i for i in range(1, 11)]

board = [[0 for _ in range(4)] for __ in range(4)]

# The number of spaces to fill
l = random.randrange(6, 12)
r = [(i, j) for i in range(4) for j in range(4)]
for x, y in random.sample(r, l):
    board[x][y] = random.choice(digits)


print("\n".join(" ".join(str(d) for d in row) for row in board))

print(random.choice(["UP", "DOWN", "LEFT", "RIGHT"]))
