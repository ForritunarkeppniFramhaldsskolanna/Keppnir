def solve():
    import sys
    import math

    # Read the total number of push-ups
    n = int(sys.stdin.readline().strip())

    # We will look for pairs (f, d) satisfying 2n = d * (2f + d - 1).
    two_n = 2 * n

    # Collect valid (f, d) pairs here
    solutions = []

    # Only need to check divisors up to sqrt(2n)
    limit = int(math.isqrt(two_n))

    for d in range(1, limit + 1):
        if two_n % d == 0:
            # d is a divisor of 2n
            other_divisor = two_n // d

            # 1) Check using d as the 'day count'
            #    2f + d - 1 = (2n / d)
            #    f = ((2n / d) - d + 1) / 2
            x = other_divisor - d + 1
            if x >= 2 and x % 2 == 0:
                f = x // 2
                if f > 0:
                    solutions.append((f, d))

            # 2) Check using 'other_divisor' as the 'day count'
            #    2f + other_divisor - 1 = (2n / other_divisor) = d
            #    f = (d - other_divisor + 1) / 2
            if other_divisor != d:  # Avoid double-checking when d^2 == 2n
                x = d - other_divisor + 1
                if x >= 2 and x % 2 == 0:
                    f = x // 2
                    if f > 0:
                        solutions.append((f, other_divisor))

    # Sort solutions in ascending order by f
    solutions.sort(key=lambda pair: pair[0])

    # Print all valid (f, d) pairs
    for f, d in solutions:
        print(f, d)


# If you want to run this directly (instead of an online judge),
# you can uncomment the lines below and provide input manually:
#
if __name__ == "__main__":
    #     # Example: input 6 => possible (f,d) pairs might be printed
    #     # Try redirecting input or modify code to test specific values
    solve()
