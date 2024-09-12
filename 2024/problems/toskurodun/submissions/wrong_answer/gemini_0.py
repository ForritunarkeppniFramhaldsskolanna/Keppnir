#!/usr/bin/python3
def optimal_checkin(n, m, Ka, Kb, Ki=[]):
    position = 1  # Start at the first position within a destination cart

    # Connecting flights (iterate in reverse)
    for k in Ki[::-1]:
        position = (
            position - 1
        ) % k + 1  # Find the last position within an aircraft stack

    # Departure airport carting
    while position > Ka:
        position = (position - 1) % Ka + 1

    # Final check-in order:
    return n - position + 1


def main():
    # Input Handling
    try:
        n, m = map(int, input().split())
        Ka, Kb = map(int, input().split())

        Ki = []  # Initialize the Ki list
        if m > 0:
            Ki = list(map(int, input().split()))

        # Input validation
        if n <= 0 or m < 0:
            raise ValueError(
                "Number of bags and connecting flights must be non-negative"
            )
        for k in [Ka, Kb] + Ki:
            if k < 1 or k > 10**18:
                raise ValueError("Cart sizes (Ka, Kb, Ki) must be between 1 and 10^18")

        # Calculation
        result = optimal_checkin(n, m, Ka, Kb, Ki)
        print(result)

    except ValueError as e:
        print("Invalid input:", e)


if __name__ == "__main__":
    main()
