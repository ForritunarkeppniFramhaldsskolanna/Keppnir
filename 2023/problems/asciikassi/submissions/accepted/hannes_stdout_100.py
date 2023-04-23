#!/usr/bin/python3
import sys

def on_boundary(i, N):
    # N+1, the first character is a side, then comes N segments, then the side again
    return (i == 0) or (i == N+1)

N = int(input())

for i in range(N+2):
    for j in range(N+2):
        # Corner
        if on_boundary(i, N) and on_boundary(j, N):
            sys.stdout.write("+")
            continue
        # Vertical edge
        elif on_boundary(j, N):
            sys.stdout.write("|")
            continue
        # Horizontal edge
        elif on_boundary(i, N):
            sys.stdout.write("-")
            continue
        # Blank space, not on a side
        else:
            sys.stdout.write(" ")
    # Force a newline
    sys.stdout.write("\n")
