#!/usr/bin/python3

def on_boundary(i, N):
    # N+1, the first character is a side, then comes N segments, then the side again
    return (i == 0) or (i == N+1)

N = int(input())

for i in range(N+2):
    s = ""
    for j in range(N+2):
        # Corner
        if on_boundary(i, N) and on_boundary(j, N):
            s += "+"
            continue
        # Vertical edge
        elif on_boundary(j, N):
            s += "|"
            continue
        # Horizontal edge
        elif on_boundary(i, N):
            s += "-"
            continue
        # Blank space, not on a side
        else:
            s += " "
    # Force a newline
    print(s)
