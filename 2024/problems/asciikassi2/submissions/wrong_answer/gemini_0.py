#!/usr/bin/python3

def draw_box(n):
    """Draws an ASCII box diagonally with side length n.

    Args:
        n: The side length of the box.
    """
    # Base case: No box for n = 0
    if n == 0:
        return

    # Calculate spaces before the first character on each line
    spaces = n - 1

    # Print the top half of the box
    for i in range(n):
        print(" " * spaces, end="")
        print("/", end="")
        print(" " * (2 * i), end="")
        print("\\")
        spaces -= 1

    # Print the bottom half of the box
    for i in range(n - 1, -1, -1):
        print(" " * spaces, end="")
        print("\\", end="")
        print(" " * (2 * i), end="")
        print("/")
        spaces += 1


# Get input for the side length
n = int(input())

# Draw the box
draw_box(n)
