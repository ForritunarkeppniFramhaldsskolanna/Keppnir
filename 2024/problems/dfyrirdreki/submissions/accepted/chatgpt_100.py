#!/usr/bin/python3
def calculate_discriminant(a, b, c):
    """Calculate the discriminant of a quadratic equation."""
    return b**2 - 4*a*c

def main():
    # Read coefficients a, b, c from standard input
    a = int(input().strip())
    b = int(input().strip())
    c = int(input().strip())

    # Calculate the discriminant
    discriminant = calculate_discriminant(a, b, c)

    # Determine the number of real-valued roots
    if discriminant > 0:
        roots = 2
    elif discriminant == 0:
        roots = 1
    else:
        roots = 0

    # Output the number of real-valued roots
    print(roots)

if __name__ == "__main__":
    main()

