#!/usr/bin/python3


def find_real_roots(a, b, c):
    """
    Finds the number of real roots in a second-degree polynomial ax^2 + bx + c.

    Args:
        a: Coefficient of the x^2 term.
        b: Coefficient of the x term.
        c: Constant term.

    Returns:
        The number of real roots (0, 1, or 2).
    """

    # Calculate the discriminant.
    discriminant = b**2 - 4 * a * c

    # Analyze the discriminant to determine the number of real roots.
    if discriminant > 0:
        return 2  # Two distinct real roots.
    elif discriminant == 0:
        return 1  # One repeated real root.
    else:
        return 0  # No real roots.


# Get input coefficients.
a = int(input())
b = int(input())
c = int(input())

# Find the number of real roots.
print(find_real_roots(a, b, c))
