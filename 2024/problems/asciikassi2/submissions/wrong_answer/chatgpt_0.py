#!/usr/bin/python3

def draw_diagonal_ascii_box(n):
    # Initialize the result list
    result = []

    # The top of the box
    for i in range(n):
        # Leading spaces
        result.append(' ' * (n - i - 1) + '/' + ' ' * (2 * i) + '\\')

    # The middle of the box, corners
    result.append('x' + ' ' * (2 * n - 2) + 'x' if n > 0 else 'x')

    # The bottom of the box
    for i in range(n - 1, -1, -1):
        # Leading spaces
        result.append(' ' * (n - i - 1) + '\\' + ' ' * (2 * i) + '/')

    return '\n'.join(result) + '\n'

# Test the function with a sample input
n = int(input())
print(draw_diagonal_ascii_box(n))

